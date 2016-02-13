// $Id: cppstrtok.cpp,v 1.3 2014-10-07 18:09:11-07 - - $

// Use cpp to scan a file and print line numbers.
// Print out each input line read in, then strtok it for
// tokens.

#include <string>
using namespace std;

#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#include "auxlib.h"
//new add
//for stringset function
#include "./stringset.h"
//for output ofstram file
#include <fstream>
//for getopt function
#include <unistd.h>

#include "./lyutils.h"
#include "./astree.h"
#include "./yyparse.h"
#include "./traverse.h"
#include "./gencode.h"
///////////////////////////


string CPP = "/usr/bin/cpp";
const size_t LINESIZE = 1024;

//new add
int opt;
const string opt_string = "lyD:@:";
char* str_file;
FILE* tokfile   =   NULL;
FILE* astfile   =   NULL;
// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

char* file_gen(char* filename, string ext ){
    string full_name  =   string(basename(filename));        
    size_t pos = full_name.rfind(".");
    string bname = full_name.substr(0, pos);
    //add file path and extension 
    string name = string(bname)+ext;
    char* file_name =new char[name.size()+1];
    copy(name.begin(), name.end(), file_name);
    file_name[name.size()]='\0';
    return file_name;
}



// Run cpp against the lines of the file.
void cpplines (FILE* pipe, char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      //printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, filename);
      if (sscanf_rc == 2) {
         printf ("DIRECTIVE: line %d file \"%s\"\n", linenr, filename);
         continue;
      }
      char* savepos = NULL;
      char* bufptr = buffer;
      //add file stream 
      str_file  =file_gen(filename,".str"); 
      ofstream fs(str_file);
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         //printf ("token %d.%d: [%s]\n",linenr, tokenct, token);
         const string* str = intern_stringset (token);
         fs<<str;
         dump_stringset (fs);
      }
      ++linenr;
      fs.close();
   }
}

int main (int argc, char** argv) {
   set_execname (argv[0]);
   int token, parsecode    =   0;
   //add debug flag option
    while ((opt = getopt(argc, argv, opt_string.c_str())) != -1){
        switch(opt){
            case '@': set_debugflags (optarg); break;
            case 'D': CPP += " -D " + string(optarg);
            case 'l': yy_flex_debug =   1; break;
            case 'y': yydebug       =   1; break;
            case '?': //thie is default case //
                      fprintf(stderr,"Unknown option: -%i\n",optopt);
                      set_exitstatus(1);
                      return get_exitstatus();
                      break;
        }
        argc-=optind;
        argv+=optind;
    }

    char* filename = argv[argc-1];
    string command = CPP + " " + filename;
    //get extension of file
    char* ext = strchr(filename, '.');
    if (ext == NULL) {
        fprintf(stderr, "Error: no extension for file\n");
        set_exitstatus(1);
        return get_exitstatus();
    }else if(strcmp(ext+1, "oc")){
        fprintf(stderr, "Error: file extension only accpet .oc\n");
        set_exitstatus(1);
        return get_exitstatus(); 
    }
    
      
    FILE* pipe = popen (command.c_str(), "r");
    if (pipe == NULL) {
        syserrprintf (command.c_str());
    }else {  
        cpplines (pipe, filename);
        int pclose_rc = pclose (pipe);
        eprint_status (command.c_str(), pclose_rc);
    }
      
 
    const char* tok_name    =   file_gen(filename,".tok");  
    const char* ast_name    =   file_gen(filename,".ast");   
    ofstream sym_file;
    ofstream oil_file;
    tokfile =   fopen(tok_name,"w");
    astfile =   fopen(ast_name,"w");
    
    sym_file.open(file_gen(filename, ".sym"), ios::out);
    oil_file.open(file_gen(filename, ".oil"), ios::out);
    yyin  =   popen(command.c_str(), "r");
    
    if(!yyin) {
        syserrprintf(command.c_str());
        exit(get_exitstatus());
    }else{       
        while( (token= yylex()) != YYEOF){ 
            yyprint(tokfile, token, yylval);
            
        }
        //close yyin 
        int pclose_rc = pclose (yyin);
        eprint_status (command.c_str(), pclose_rc);
          
    }
                
    yyin  =   popen(command.c_str(), "r");
    
    if(!yyin) {
        syserrprintf(command.c_str());
        exit(get_exitstatus());
    }else{       
        parsecode=yyparse();   
        if(!parsecode){
            type_check(sym_file,yyparse_astree);
            dump_astree(astfile, yyparse_astree);
            gencode(oil_file ,yyparse_astree);
            oil_file.close();
        }
        //close yyin 
        int pclose_rc = pclose (yyin);
        eprint_status (command.c_str(), pclose_rc);      
    }

  return get_exitstatus();
}

