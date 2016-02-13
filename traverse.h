// =====================================================================================
//
//       Filename:  traverse.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  11/26/2015 06:41:32 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chih-Yu Hsu (Chihyu), chihyu.hsu1114@gmail.com
//   Organization:  University of California Santa Cruz
//
// =====================================================================================
#ifndef _TRAVERSE_H_
#define _TRAVERSE_H_
#include "./astree.h"
#include "./auxlib.h"
#include <assert.h>
#include <queue>  

void type_check(ofstream&,astree*);
void traverse(astree*);
void build_struct(astree*);
void build_func(astree*);
bool is_primitive(astree*);
bool is_ref(astree*);
bool is_int(astree*);
bool check_compatible(astree*, astree*);
void set_type(astree*);
void pass_type(astree*,astree*);
void traverse_blk(astree*);
void get_attr(ofstream&, astree*);
void print_sym(ofstream&,astree*);
extern queue<astree*> strque; 
#endif
