// =====================================================================================
//
//       Filename:  gencode.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/01/2015 01:15:13 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chih-Yu Hsu (Chihyu), chihyu.hsu1114@gmail.com
//   Organization:  University of California Santa Cruz
//
// =====================================================================================
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "./astree.h"
#include "./traverse.h"
#include "./parser.tab.h"

string typemap(astree*);
string name_mangle(astree*);
string keyword_mangle(astree*); 
void gencode(ofstream&, astree*);
void structdef(ofstream&, astree*);
void stringdef(ofstream&, astree*);
void vardecl(ofstream&, astree*);
void fnbody(ofstream&, astree*);
void whiledecl(ofstream&, astree*);
void condition_gen(ofstream&, astree*);
void gen_assign(ofstream&, astree*);
void statements(ofstream&, astree*);
void alloc(ofstream&, astree*);
void gen_call(ofstream&, astree*);
void operand(ofstream&, astree*);
void exprs(ofstream&, astree*);
void gen_if(ofstream&, astree*);
void gen_return(ofstream&, astree*);
void binop_expr(ofstream&, astree*);
void unop_expr(ofstream&, astree*);
string reg_var(string);
void funcdecl(ofstream&, astree*);
