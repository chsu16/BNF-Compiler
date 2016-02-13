
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "stringset.h"
#include "lyutils.h"
#include "./symbol-table-code.h"

astree::astree (int symbol, int filenr, int linenr,
                int offset, const char* clexinfo):
        symbol (symbol), filenr (filenr), linenr (linenr),
        offset (offset), lexinfo (intern_stringset (clexinfo)) {
        int blk_nr=0; attr_bitset attr=0; int reg_nr=0;
        DEBUGF ('f', "astree %p->{%d:%d.%d: %s: \"%s\"}\n",
           (void*) this, filenr, linenr, offset,
           get_yytname (symbol), lexinfo->c_str());
}

astree* adopt1 (astree* root, astree* child) {
   root->children.push_back (child);
   DEBUGF ('a', "%p (%s) adopting %p (%s)\n",
           root, root->lexinfo->c_str(),
           child, child->lexinfo->c_str());
   return root;
}

astree* adopt2 (astree* root, astree* left, astree* right) {
   adopt1 (root, left);
   adopt1 (root, right);
   return root;
}

astree* adopt3 (astree* root, astree* first, astree* second, astree* third){
    adopt2(root, first, second);
    adopt1(root, third);
    return root;
}

void swap(astree* node, int tok_code){
    node->symbol    =   tok_code;
}

static void dump_ast_node(FILE* outfile, astree* node){
    const char* tname  =   get_yytname(node->symbol);
    if(strstr(tname,"TOK_") == tname) tname+=4;
    fprintf(outfile,"%-s \"%s\" %lu.%lu.%-2lu.{%d}\n" , tname ,node->lexinfo->c_str(),node->filenr,node->linenr,node->offset,node->blk_nr); 
}
static void dump_node (FILE* outfile, astree* node) {
   /*fprintf (outfile, "%p->{%s(%d) %ld:%ld.%03ld \"%s\" [",
            node, get_yytname (node->symbol), node->symbol,
            node->filenr, node->linenr, node->offset,
            node->lexinfo->c_str());*/
    
    fprintf(outfile, "%4lu%4lu.%.03lu %4d  %-15s (%s)\n", 
    node->filenr, node->linenr, node->offset,
    node->symbol, get_yytname (node->symbol), 
    node->lexinfo->c_str());
    
   /*  
   bool need_space = false;
   for (size_t child = 0; child < node->children.size();
        ++child) {
      if (need_space) fprintf (outfile, " ");
      need_space = true;
      fprintf (outfile, " %p", node->children.at(child));
   }
   */
   /*
   fprintf (outfile, "]}");
   */
}

static void dump_astree_rec (FILE* outfile, astree* root,
                             int depth) {
   if (root == NULL) return;
   
    /*
   fprintf (outfile, "%*s%s ", depth * 3, "",
           root->lexinfo->c_str());
   */
   int step = depth;
   while(step){
    fprintf (outfile, "%-*c ", 2 , '|');
    step--;
   }
   dump_ast_node (outfile, root);
   fprintf (outfile, "\n");
   for (size_t child = 0; child < root->children.size();
        ++child) {
      dump_astree_rec (outfile, root->children[child],
                       depth + 1);
   }
}

void dump_astree (FILE* outfile, astree* root) {
   dump_astree_rec (outfile, root, 0);
   fflush (NULL);
}

void yyprint (FILE* outfile, unsigned short toknum,
              astree* yyvaluep) {
   if (is_defined_token (toknum)) {
      dump_node (outfile, yyvaluep);
   }else {
      fprintf (outfile, "%s(%d)\n",
               get_yytname (toknum), toknum);
   }
   fflush (NULL);
}


void free_ast (astree* root) {
   while (not root->children.empty()) {
      astree* child = root->children.back();
      root->children.pop_back();
      free_ast (child);
   }
   DEBUGF ('f', "free [%p]-> %d:%d.%d: %s: \"%s\")\n",
           root, root->filenr, root->linenr, root->offset,
           get_yytname (root->symbol), root->lexinfo->c_str());
   delete root;
}

void free_ast2 (astree* tree1, astree* tree2) {
   free_ast (tree1);
   free_ast (tree2);
}

RCSC("$Id: astree.cpp,v 1.6 2015-04-09 19:31:47-07 - - $")

