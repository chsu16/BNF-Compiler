%{
// Dummy parser for scanner project.

#include "lyutils.h"
#include "astree.h"
#include <assert.h>
%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE

%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON
%token TOK_FIELDS TOK_FIELDDECL TOK_BASETYPE TOK_FUNCTION TOK_PROTOTYPE TOK_IDENTDECL
%token TOK_PARAM TOK_DECLID  TOK_VARDECL TOK_RETURNVOID TOK_NEWSTRING
%token TOK_EXPRLIST TOK_INDEX  

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token TOK_ORD TOK_CHR TOK_ROOT

%right TOK_IF TOK_ELSE TOK_IFELSE
%right '='
%left  TOK_EQ TOK_NE TOK_GT TOK_GE TOK_LE TOK_LT
%left  '+' '-'
%left  '*' '/' '%'
%right TOK_POS TOK_NEG '!' TOK_NEW TOK_ORD TOK_CHR
%left  '[' ']' '.' '(' ')'

%start start

%%
start   : program             {yyparse_astree = $1; }
        ;                                                         
program : program structdef  { $$ = adopt1 ($1, $2); }             
        | program function   { $$ = adopt1 ($1, $2); }             
        | program statement  { $$ = adopt1 ($1, $2); }             
        | program error '}'  { $$ = $1; }                          
        | program error ';'  { $$ = $1; }                          
        |                    { $$ = new_parseroot (); }            
        ;       

structdef   : TOK_STRUCT TOK_IDENT '{' fields '}'   { swap($2,TOK_TYPEID); $$ = adopt2($1,$2,$4);free_ast2($3,$5); }
            ;
fields      : fields fielddecl ';'                  { $$ = adopt1($1,$2);free_ast($3); }
            |                                       { $$ = new_parsenode(TOK_FIELDS,"fields"); }
            ;
fielddecl   : basetype TOK_ARRAY TOK_IDENT          { swap($3,TOK_FIELD); $$ = adopt2($1,$3,$2); }
            | basetype TOK_IDENT                    { swap($2,TOK_FIELD); $$ = adopt1($1,$2); }
            ;
basetype    : TOK_VOID                              { $$ = $1;}
            | TOK_BOOL                              { $$ = $1;}
            | TOK_CHAR                              { $$ = $1;}
            | TOK_INT                               { $$ = $1;}
            | TOK_STRING                            { $$ = $1;}
            | TOK_IDENT                             { $$ = $1;}
            ;
function    : identdecl prototype ')' block         { $$ = adopt3(new_parsenode(TOK_FUNCTION,"function"),$1,$2,$4);free_ast($3);}
            ;
prototype   : prototype ',' identdecl               { $$ = adopt1($1,$3); free_ast($2); }
            | '(' identdecl                         { swap($1,TOK_PARAM); $$ = adopt1($1,$2); }
            | '('                                   { swap($1,TOK_PARAM); $$ = $1;}
            ;
identdecl   : basetype TOK_IDENT                    { swap($2,TOK_DECLID); $$ = adopt1($1,$2);}    
            | basetype TOK_ARRAY TOK_IDENT          { swap($3,TOK_DECLID); $$ = adopt2($1,$3,$2);}            
            ;

block       : state '}'                             { $$=$1; free_ast($2);  }              
            | '{' '}'                               {swap($1,TOK_BLOCK); $$ = $1; free_ast($2);}
            | ';'                                   { $$ = new_parsenode(TOK_BLOCK,"block"); free_ast($1);}                                 
            ;
state       : state statement                       { $$ = adopt1($1,$2); }
            | '{' statement                         { swap($1,TOK_BLOCK); $$ = adopt1($1,$2); }
            ;            ;
statement   : block                                 {$$ = $1;}
            | vardecl                               {$$ = $1;}
            | while                                 {$$ = $1;}
            | ifelse                                {$$ = $1;}
            | return                                {$$ = $1;}
            | expr ';'                              {$$ = $1;}
            ;
vardecl     : identdecl '=' expr ';'                {swap($2,TOK_VARDECL); $$ = adopt2($2,$1,$3); free_ast($4);}
            ;
while       : TOK_WHILE '(' expr ')' statement      {$$ = adopt2($1,$3,$5); free_ast2($2,$4);}
            ;
ifelse      : TOK_IF '(' expr ')' statement %prec TOK_ELSE      {/*$$ = adopt2(new_parsenode(TOK_IFELSE,"ifelse"),$3,$5);*/ 
            $$ = adopt2($1,$3,$5);/*free_ast($1)*/;free_ast2($2,$4);}
            | TOK_IF '(' expr ')' statement TOK_ELSE statement { $$ = adopt3(new_parsenode(TOK_IFELSE,"ifelse"),$3,$5,$7); free_ast2($1,$6);free_ast2($2,$4);}
            ;
return      : TOK_RETURN ';'                        { swap($1, TOK_RETURNVOID); $$=$1; free_ast($2);}
            | TOK_RETURN expr ';'                   { $$ = adopt1($1,$2); free_ast($3); }
            ;   
expr        : binop                                 { $$=$1; }
            | unop                                  { $$=$1; }
            | allocator                             { $$=$1; }
            | call                                  { $$=$1; }
            | '(' expr ')'                          { free_ast2($1,$3); $$=$2; }
            | variable                              { $$=$1; }
            | constant                              { $$=$1; }
            ;
binop       : expr '='    expr                      { $$ = adopt2($2,$1,$3); }
            | expr TOK_EQ expr                      { $$ = adopt2($2,$1,$3); }
            | expr TOK_NE expr                      { $$ = adopt2($2,$1,$3); }
            | expr TOK_LT expr                      { $$ = adopt2($2,$1,$3); }
            | expr TOK_LE expr                      { $$ = adopt2($2,$1,$3); }
            | expr TOK_GT expr                      { $$ = adopt2($2,$1,$3); }
            | expr TOK_GE expr                      { $$ = adopt2($2,$1,$3); }
            | expr '*'    expr                      { $$ = adopt2($2,$1,$3); }
            | expr '/'    expr                      { $$ = adopt2($2,$1,$3); }
            | expr '%'    expr                      { $$ = adopt2($2,$1,$3); }
            | expr '+'    expr                      { $$ = adopt2($2,$1,$3); }
            | expr '-'    expr                      { $$ = adopt2($2,$1,$3); }
            ;
unop        : '+' expr                              {swap($1,TOK_POS); $$ = adopt1($1,$2); }
            | '-' expr                              {swap($1,TOK_NEG); $$ = adopt1($1,$2); }
            | '!' expr                              {$$ = adopt1($1,$2); }
            | TOK_ORD expr                          { $$ = adopt1($1,$2); }
            | TOK_CHR expr                          { $$ = adopt1($1,$2); }
            ;
allocator   : TOK_NEW TOK_IDENT '(' ')'             {swap($2,TOK_TYPEID); $$ = adopt1($1,$2); free_ast2($3,$4);}
            | TOK_NEW TOK_STRING '(' expr ')'       {swap($1,TOK_NEWSTRING); $$ = adopt1($1,$4);free_ast($2); free_ast2($3,$4);}
            | TOK_NEW basetype '[' expr ']'         {swap($1,TOK_NEWARRAY); $$ = adopt2($1,$2,$4); free_ast2($3,$5);}
            ;
call        : TOK_IDENT '(' exprlist ')'            {swap($2,TOK_CALL); $$ = adopt2($2,$1,$3); free_ast($4);}
            ;
exprlist    : exprlist ',' expr                     { $$ = adopt1($1,$3); free_ast($2); }
            | expr                                  { $$ = $1; }
            |                                       { $$ = new_parsenode(TOK_EXPRLIST,"exprlist"); }
            ;
variable    : TOK_IDENT                             { $$ = $1; }                             
            | expr '[' expr ']'                     { swap($2,TOK_INDEX); $$ = adopt2($2,$1,$3); free_ast($4); }
            | expr '.' TOK_IDENT                    { swap($3,TOK_FIELD); $$ = adopt2($2,$1,$3);}
            ;
constant    : TOK_INTCON                            { $$ = $1; } 
            | TOK_CHARCON                           { $$ = $1; }
            | TOK_STRINGCON                         { $$ = $1; }
            | TOK_FALSE                             { $$ = $1; }
            | TOK_TRUE                              { $$ = $1; }
            | TOK_NULL                              { $$ = $1; }
            ;
%%

const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}

