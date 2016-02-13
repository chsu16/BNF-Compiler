%{
#include "./astree.h"
#include "./lyutils.h"
#define IGNORE(THING)   { }

%}

%option 8bit
%option debug
%option ecs
%option nodefault
%option nounput
%option noyywrap
%option perf-report
%option verbose
%option warn

LETTER          [A-Za-z_]
DIGIT           [0-9]
CHAR            ('([^\\'\n]|\\[\\'"0nt])')
STRING          (\"([^\\"\n]|\\[\\'"0nt])*\")
INTEGER         ({DIGIT}+)
NUMBER          ({INTEGER})
IDENT           ({LETTER}({LETTER}|{DIGIT})*)
NOTIDENT        (({LETTER}|{DIGIT})*)
NOTCHAR         ('([^\\'\n]|\\.)'?)
NOTSTRING       (\"([^\\"\n]|\\.)*(\")?)

%%

void            { return yylval_token(TOK_VOID); }
bool            { return yylval_token(TOK_BOOL); }
char            { return yylval_token(TOK_CHAR); }
int             { return yylval_token(TOK_INT); }
string          { return yylval_token(TOK_STRING); }
struct          { return yylval_token(TOK_STRUCT); }
if              { return yylval_token(TOK_IF); }
else            { return yylval_token(TOK_ELSE); }
while           { return yylval_token(TOK_WHILE); }
return          { return yylval_token(TOK_RETURN); }
new             { return yylval_token(TOK_NEW); }
false           { return yylval_token(TOK_FALSE); }
true            { return yylval_token(TOK_TRUE); }
null            { return yylval_token(TOK_NULL); }
ord             { return yylval_token(TOK_ORD); }
chr             { return yylval_token(TOK_CHR); }

{NUMBER}        { return yylval_token (TOK_INTCON); }
{IDENT}         { return yylval_token (TOK_IDENT); }

{CHAR}          { return yylval_token (TOK_CHARCON); }
{STRING}        { return yylval_token (TOK_STRINGCON); }

"[]"            { return yylval_token (TOK_NEWARRAY); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }
";"             { return yylval_token (';'); }
","             { return yylval_token (','); }
"."             { return yylval_token ('.'); }
"="             { return yylval_token ('='); }
"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<"             { return yylval_token (TOK_LT); }
"<="            { return yylval_token (TOK_LE); }
">"             { return yylval_token (TOK_GT); }
">="            { return yylval_token (TOK_GE); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"%"             { return yylval_token ('%'); }
"!"             { return yylval_token ('!'); }


{NOTIDENT}      { lexer_badtoken (yytext);
                  return yylval_token (TOK_IDENT); }

{NOTCHAR}       { lexer_badtoken (yytext);
                  return yylval_token (TOK_CHARCON); }
{NOTSTRING}     { lexer_badtoken (yytext);
                  return yylval_token (TOK_STRINGCON); }

"#".*           { lexer_include(); }
[ \t]+          { IGNORE (white space) }
\n              { lexer_newline(); }

.               { lexer_badchar (*yytext); }

%%

