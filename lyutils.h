#ifndef __LYUTILS_H__
#define __LYUTILS_H__

// Lex and Yacc interface utility.

#include <stdio.h>

#include "astree.h"
#include "auxlib.h"

#define YYEOF 0

extern FILE* yyin;
extern astree* yyparse_astree;
extern int yyin_linenr;
extern char* yytext;
extern int yy_flex_debug;
extern int yydebug;
extern int yyleng;
extern FILE* tokfile;

int yylex (void);
int yyparse (void);
void yyerror (const char* message);
int yylex_destroy (void);
const char* get_yytname (int symbol);
bool is_defined_token (int symbol);

const string* lexer_filename (int filenr);
void lexer_newfilename (const char* filename);
void lexer_badchar (unsigned char bad);
void lexer_badtoken (char* lexeme);
void lexer_newline (void);
void lexer_setecho (bool echoflag);
void lexer_useraction (void);

astree* new_parseroot (void);
astree* new_parsenode (int node_symbol,const char* node_lexinfo);
int yylval_token (int symbol);

void lexer_include (void);

typedef astree* astree_pointer;
#define YYSTYPE astree_pointer
#include "yyparse.h"

RCSH("$Id: lyutils.h,v 1.3 2015-04-09 17:45:26-07 - - $")
#endif
