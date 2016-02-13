#include <vector>
#include "./traverse.h"
#include "./symbol-table-code.h"
#include "./parser.tab.h"
#include <iostream>

symbol_table* global_table;
vector<symbol_table*> symbol_stack;
vector<int> blk_count;
int next_block;

void type_check(ofstream& out,astree* root){
    symbol_table global_hash;
    global_table = &global_hash;
    symbol_stack.push_back(global_table); 
    next_block  =   1;
    blk_count.push_back(0);
    traverse(root);
    /*
    for(auto& x:*symbol_stack[symbol_stack.size()-1]){
                string  first   =   *x.first;
                cout<<first<<" ==== "<<(x.second)->attributes<<endl;
    }
    */
    print_sym(out, root);
}
bool is_primitive(astree* root){
    if( root->attr[ATTR_bool] ||  root->attr[ATTR_char] || root->attr[ATTR_int] )
        return true;
    return false;
}
bool is_ref(astree* root){
    if( root->attr[ATTR_typeid]==1 || root->attr[ATTR_null]==1)
        return true;
    return false;
}
bool is_int(astree* root){
    if(root->attr[ATTR_int])
        return true;
    return false;
}
bool check_compatible(astree* left, astree* right){
    //check for type attributes in according bits
    attr_bitset ltype    =   left->attr;
    attr_bitset rtype    =   left->attr;
    if(ltype<<14 == rtype<<14)
        return true;
    else if(is_ref(left) && right->attr[ATTR_null]==1)
        return true;
    else 
        return false;        
}

void set_type(astree* root){ 
    switch(root->symbol){
        //primitive type
        case TOK_BOOL:
            root->attr[ATTR_bool]=1;
            break;
        case TOK_CHAR:
            root->attr[ATTR_char]=1;
            break;
        case TOK_INT:
            root->attr[ATTR_int]=1;
            break;
        //reference type
        case TOK_STRING:
            root->attr[ATTR_string]=1;
            break;
        case TOK_TYPEID:
            root->attr[ATTR_typeid]=1;
    }
}

void pass_type(astree* root, astree* child){
            child->attr |= root->attr; 
}

void build_struct(astree* root){
        astree* type_id =   root->children[0];
        if(!look_up(symbol_stack,type_id->lexinfo)){
            pass_type(root,type_id);
            symbol* sym =   new symbol(type_id->attr, type_id->filenr, type_id->linenr, type_id->offset, 0);
            symbol_entry entry  =   make_pair(type_id->lexinfo, sym); 
            insertion(symbol_stack,entry);
         
            if(root->children[1]->symbol == TOK_FIELDS){
                symbol_table field_hash;
                astree* fields  =   root->children[1];
                if(fields->children.size()>0){
                    for(auto field:fields->children){
                        if(is_primitive(field) || is_ref(field)){
                            astree* ident   =   field->children[0];
                            pass_type(field,ident);
                            symbol* field_sym   =   new symbol(ident->attr,ident->filenr, ident->linenr,ident->offset,0);
                            symbol_entry field_entry    =   make_pair(ident->lexinfo, field_sym);
                            field_hash.insert(field_entry);
                        }   
                    }
                }
            sym->fields =   &field_hash;
            }
        }
}

void build_func(astree* root){
    astree* func_decl   =   root->children[0];
    astree* func_name   =   func_decl->children[0];
    pass_type(func_decl,func_name);
    symbol* func_sym    =   search_symbol(symbol_stack, *func_name->lexinfo);
    //symbol* func_sym    =   new symbol(func_name->attr, func_name->filenr, func_name->linenr, func_name->offset, blk_count.back());
    //symbol_entry func_entry =   make_pair(func_name->lexinfo, func_sym);
    //insertion(symbol_stack, func_entry);
    //cout<<*func_name->lexinfo<<"{"<<func_name->blk_nr<<"}"<<endl;    
    
    astree* param_list  =   root->children[1];
    vector<symbol*> param_vec   =   {};
    for(auto param_type:param_list->children){
        astree* param = param_type->children[0];
        pass_type(param_type,param);
        //param->blk_nr       =   func_sym->blocknr+1;
        symbol* param_sym   =   new symbol(param->attr,param->filenr, param->linenr, param->offset, param->blk_nr);
        param_vec.push_back(param_sym);
    }
    func_sym->parameters = &param_vec;
    /*for(auto child: *func_sym->parameters){
        cout<<"param: "<<child->linenr<<" "<<child->offset<<endl;
    } */   
}


void traverse(astree* root){
    if(!root) return;
    for(int child = 0; child<root->children.size(); ++child){
        if(root->children[child]->symbol == TOK_BLOCK || root->children[child]->symbol == TOK_PARAM ){
           root->children[child]->blk_nr = next_block;
           enter_blk(symbol_stack);
        }
        
        if(root->children[child]->symbol == TOK_DECLID){
            astree* id  = root->children[child];   
            id->attr[ATTR_variable]  =   1;
            id->attr[ATTR_lval]      =   1;
 
            id->blk_nr   =   blk_count.back();
            symbol* declid  =   new symbol(id->attr,id->filenr,id->linenr,id->offset,blk_count.back()); 
            symbol_entry id_entry   =   make_pair(id->lexinfo, declid);
            insertion(symbol_stack,id_entry);
            //cout<<*id->lexinfo<<"{"<<id->blk_nr<<"}"<<endl;
        }
        
        traverse(root->children[child]);
    }        
    //start type checking and attributes assignement
    switch(root->symbol){
        case TOK_VOID:
            root->attr[ATTR_void]=1;
            break;
        //primitive type
        case TOK_BOOL:
        case TOK_CHAR:
        case TOK_INT:
        case TOK_STRING: 
        //reference type
        case TOK_TYPEID:
            set_type(root);
            break;    
        case TOK_NULL:
            root->attr[ATTR_null]=1;
            break;
        case TOK_STRUCT: 
            root->attr[ATTR_struct]=1;
            build_struct(root);
            break;
       case TOK_ARRAY:
            root->attr[ATTR_array]=1; 
            break;
        //function
        case TOK_FUNCTION:
            root->attr[ATTR_function]=1;
            build_func(root); 
            break;    
        case TOK_PARAM:
            leave_blk(symbol_stack);
            break;
        case TOK_VARDECL:
            if(!check_compatible(root->children[0], root->children[1]))
                errprintf ("incompatible type on both side:\"%s\" .%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);

            if(!root->children[0]->attr[ATTR_void]){ 
                //set attributes for variable in variable declaration
                for(auto child:root->children[0]->children){
                    if(child->symbol == TOK_ARRAY && root->children[1]->symbol == TOK_ARRAY)
                        errprintf ("invalid declare array type to array :\"%s\" .%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
                    if(child->symbol == TOK_DECLID){
                        pass_type(root->children[0],child);
                        /*
                        child->attr[ATTR_variable]  =   1;
                        child->attr[ATTR_lval]      =   1;
                        
                        child->blk_nr               =   blk_count.back();
                        symbol* declid  =   new symbol(child->attr,child->filenr,child->linenr,child->offset,blk_count.back()); 
                        symbol_entry id_entry   =   make_pair(child->lexinfo, declid);
                        insertion(symbol_stack,id_entry);
                        cout<<*child->lexinfo<<"{"<<child->blk_nr<<"}"<<endl;
                        */
                    }
                }               
                root->attr  =   root->children[0]->attr;
                break;        
            }
            errprintf ("invalid declare void in variable:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
        
        case TOK_WHILE:
            //if(!root->children[0]->attr[ATTR_bool])
                //errprintf ("while expression should have bool attributes:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
            break;
        case TOK_IFELSE:
            //if(!root->children[0]->attr[ATTR_bool])
                errprintf ("if expression should have bool attributes:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
            break;
        case '=':
            if(root->children[0]->attr[ATTR_lval]){
                for(auto child:root->children)   
                    child->attr[ATTR_vreg]=1;
            }
            break;
        case TOK_EQ:
        case TOK_NE:
            root->attr[ATTR_vreg]=1;
            root->attr[ATTR_bool]=1;
            break;
        case TOK_LT:
        case TOK_LE:
        case TOK_GT:
        case TOK_GE:
            if(is_primitive(root->children[0]) && is_primitive(root->children[1])){   
                root->attr[ATTR_bool]=1;
                root->attr[ATTR_vreg]=1;
             }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            if(is_int(root->children[0]) && is_int(root->children[1])){ 
                root->attr[ATTR_int]=1;
                root->attr[ATTR_vreg]=1;
            }
            break;
        case TOK_POS:
        case TOK_NEG:
        case '!':
            if(is_int(root->children[0])){
                root->attr[ATTR_int]=1;
                root->attr[ATTR_vreg]=1;
            }
            break;
        case TOK_ORD:
            if(root->children[0]->attr[ATTR_char]){
                root->attr[ATTR_int]=1;
                root->attr[ATTR_vreg]=1;
            }
            errprintf ("only ord on chars:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
            break;
        case TOK_CHR:
             if(root->children[0]->attr[ATTR_int]){
                root->attr[ATTR_char]=1;
                root->attr[ATTR_vreg]=1;
            }
            errprintf ("only chr on int:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
            break;
        case TOK_NEW:
            if(!look_up(symbol_stack, root->children[0]->lexinfo))
                errprintf ("struct is not defined:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
            if(root->children[0]->symbol == TOK_TYPEID){
                root->attr  =   root->children[0]->attr;
                root->attr[ATTR_vreg]=1;
            }else if ((root->children[0]->symbol == TOK_NEWSTRING) && (root->children[1]->symbol == TOK_INT) ){
                root->attr[ATTR_string]=1;
                root->attr[ATTR_vreg]=1;
            }else if ((root->children[0]->symbol == TOK_NEWARRAY) && (root->children[1]->symbol == TOK_INT) ){
                root->attr  =   root->children[0]->attr;
                root->attr[ATTR_vreg]=1;
            }
            break;
        case TOK_CALL:
            break;
        case TOK_IDENT:
            root->attr[ATTR_variable]=1;
            break;
        case TOK_INTCON:
            root->attr[ATTR_int]=1;
            root->attr[ATTR_const]=1;
            break;
        case TOK_CHARCON:
            root->attr[ATTR_char]=1;
            root->attr[ATTR_const]=1;
            break;
        case TOK_STRINGCON:
            root->attr[ATTR_string]=1;
            root->attr[ATTR_const]=1;
            break;
        case TOK_FALSE:
        case TOK_TRUE:
            root->attr[ATTR_bool]=1;
            root->attr[ATTR_const]=1;
            break;
        case TOK_FIELD:
            root->attr[ATTR_field]=1;
            break;
        case TOK_BLOCK:
            leave_blk(symbol_stack);
            //cout<<"leave "<<blk_count.back()<<endl;
            break;
        case '.':
            auto get = symbol_stack[0]->find(root->children[0]->lexinfo);
            if(get == symbol_stack[0]->end())
                errprintf ("structure is not defined:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
            else if (get->second->fields->find(root->children[1]->lexinfo) == get->second->fields->end()) 
                errprintf ("field is not defined:\"%s\".%lu.%-2lu\n",root->lexinfo->c_str(),root->linenr,root->offset);
            break;
        }
    
}

/*
void get_attr(ofstream& out, astree* root){
    if(root->attr[ATTR_function]==1)
        out<<"function ";
    if(root->attr[ATTR_variable]==1)
        out<<"variable ";
    if(root->attr[ATTR_field]==1)
        out<<"field ";
    if(root->attr[ATTR_param]==1)
        out<<"param ";
    if(root->attr[ATTR_lval]==1)
        out<<"lval "<<endl;
}
*/

void print_sym(ofstream& out,astree* root){
   /* for(auto child: root->children){
        switch (child->symbol) {
            case TOK_STRUCT:    
                out<<*child->children[0]->lexinfo
                out<<"("+child->filenr+"."+child->linenr+"."+child->offset+" ";
                out<<"{0} struct "<<"\""<<*child->children[0]->lexinfo<<"\""<<endl;
                for(int i=1; i<root->children.size(); ++i){
                    out<<string(3,' ');
                    astree* field   =   root->children[i];
                    out<<*field->children[0]->lexinfo
                    out<<"("+root->children[0]->filenr+"."+field->linenr+"."+field->offset+" ";
                    out<<"field "<<"{"<<*root->lexinfo<<"}"<<endl;

        
                }
        }   
    }
    */
}

 /*    switch (node->symbol) {
        case TOK_STRUCT:    if (!node->attributes[ATTR_array]) {
                                write_struct(out, node, depth);
                                break;
                            }
        default:            write_node(out, node, depth);
                            if (node->children.empty()) break;
                            for (astree* child: node->children) {
                                assert(child != nullptr);
                                print_sym(out, child, depth+1);
                            }
    }
*/

