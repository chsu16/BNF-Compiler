// $Id: symbol-table-code.cpp,v 1.6 2015-05-13 14:40:56-07 - - $
#ifndef _SYMBOL_TABLE_CODE_H_
#define _SYMBOL_TABLE_CODE_H_

#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

enum ATTR { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
       ATTR_string, ATTR_struct, ATTR_array, ATTR_function,
       ATTR_variable, ATTR_field, ATTR_typeid, ATTR_param,
       ATTR_lval, ATTR_const, ATTR_vreg, ATTR_vaddr,
       ATTR_bitset_size,
};
using attr_bitset = bitset<ATTR_bitset_size>;

struct symbol;
using symbol_table = unordered_map<const string*,symbol*>;
using symbol_entry = symbol_table::value_type;

struct symbol {
   attr_bitset attributes;
   symbol_table* fields;
   size_t filenr, linenr, offset;
   size_t blocknr;
   vector<symbol*>* parameters;
   symbol(attr_bitset attributes, int filenr,int linenr, int offset, int blocknr):
   attributes(attributes),filenr(filenr),linenr(linenr),offset(offset),blocknr(blocknr)
   { fields=nullptr; parameters=nullptr;}
};
  
extern vector<symbol_table*> symbol_stack;
extern symbol_table* global_table;
extern vector<int> blk_count; 
extern int next_block;

void enter_blk(vector<symbol_table*>);
void leave_blk(vector<symbol_table*>);
void insertion(vector<symbol_table*> ,symbol_entry);
bool look_up(vector<symbol_table*>, const string*);
symbol* search_symbol(vector<symbol_table*>, string);
string get_type(symbol*);
string get_attr(symbol*);
#endif
