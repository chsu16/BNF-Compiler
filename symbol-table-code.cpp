// $Id: symbol-table-code.cpp,v 1.6 2015-05-13 14:40:56-07 - - $
#include <iostream>
#include "./symbol-table-code.h"

using namespace std;

int next_blk=1;

void enter_blk(vector<symbol_table*> symbol_stack){
    blk_count.push_back(next_blk); 
    next_blk++;
    symbol_stack.push_back(nullptr);
    //cout<<"top to "<<symbol_stack.size()-1<<endl;
} 
void leave_blk(vector<symbol_table*> symbol_stack){
    next_blk--;
    if(!symbol_stack.empty())
        symbol_stack.pop_back();
    blk_count.pop_back();
    //cout<<"down to "<<symbol_stack.size()-1;
}
void insertion(vector<symbol_table*> symbol_stack ,symbol_entry entry ){
    if(symbol_stack[symbol_stack.size()-1]==nullptr) {
        symbol_table new_symtable;
        symbol_stack[symbol_stack.size()-1]   =   &new_symtable;
    }
    symbol_stack[symbol_stack.size()-1]->insert(entry);
    //cout<<"insert at:  "<<symbol_stack.size()-1<<endl;
}
bool look_up(vector<symbol_table*> symbol_stack,const string* key){
    for(auto& x:*symbol_stack[symbol_stack.size()-1]){
                string  first   =   *x.first;
                if(first.compare(*key))
                    return true;
    }
    return false;
}

symbol* search_symbol(vector<symbol_table*> symbol_stack, string key){
  /*  
    for(int i=symbol_stack.size()-1; i>=0; --i){
        auto get = (symbol_stack[i]->find(key));
        if(get != (symbol_stack[i]->end()))
            return get->second;
    }
    return nullptr;
*/      
    for(auto& x:*symbol_stack[symbol_stack.size()-1]){
                string  first   =   *x.first;
                if(first.compare(key))
                    return (x.second);
    } 
    return nullptr;

}

string get_type(symbol* sym){
    if(sym->attributes[ATTR_int]==1)
        return "int";
    if(sym->attributes[ATTR_char]==1)
        return "char";
    if(sym->attributes[ATTR_string]==1)
        return "string";
    if(sym->attributes[ATTR_bool]==1)
        return "bool";
    if(sym->attributes[ATTR_struct]==1)
        return "struct";
}


