#include <typeinfo>
#include "./gencode.h"
#include "./symbol-table-code.h"
using namespace std;

string indent = string(8,' ');
int reg_count   =   0;

string typemap(astree* root){
    string type;
    switch(root->symbol){
        case TOK_INT:
            type    =   "int ";
            break;
        case TOK_CHAR:
            type    =   "char ";
            break;
        case TOK_BOOL:
            type    =   "char ";
            break;
        case TOK_STRING:
            type    =   "char* ";           
            break;
        case TOK_IDENT:
            type    =   "struct s_"+*root->lexinfo + "*";
            break;
    }
    return type;
}

string name_mangle(astree* root){
    string name     =   "";
    string prefix   =   "_";
    if(!root->blk_nr){
        switch(root->symbol){
            case TOK_TYPEID:
                name = "s_"+ *root->lexinfo;
                break;
            case TOK_DECLID:
                name = prefix+"_"+*root->lexinfo;
                break;
            case TOK_IDENT:
                name = prefix+"_"+*root->lexinfo;
            case TOK_INTCON:
                name = *root->lexinfo;
        }
    }
    else{
        name    =   *root->lexinfo;
        prefix  +=  to_string(root->blk_nr)+"_";
        name    =   prefix+name;
    }
    return name;    
}

string keyword_mangle(astree* root){
    string keywords="";
    switch(root->symbol){
        case TOK_IFELSE:
        case TOK_IF:
        case TOK_WHILE:
            keywords    =   *root->lexinfo+"_"+to_string(root->filenr)+"_"+to_string(root->linenr)+"_"+to_string(root->offset);
            break;        
    }
    return keywords;
}

void structdef(ofstream& out,astree* root){
    string type_id  =   name_mangle(root->children[0]);   
    out<<"struct "<<type_id<<"{"<<endl;
    astree* fields  =   root->children[1];
    string field_prefix =   "f_"+ *root->children[0]->lexinfo+"_";
    for(int i=0; i<fields->children.size(); ++i){
        string field_type   =   typemap(fields->children[i]);
        string field_name   =   field_prefix + *fields->children[i]->children[0]->lexinfo;       
        out<<indent<<field_type+" "+field_name<<";"<<endl;
    }
    out<<"};"<<endl;
}
void stringdef(ofstream& out,astree* root){
    astree* old_type = root->children[0];
    astree* old_name = root->children[0]->children[0];
    string type = "char* ";
    string name = name_mangle(old_name);
    out<<type+" "+name+" = "<<*root->children[1]->lexinfo<<endl;
}
void vardecl(ofstream& out,astree* root){
    astree* old_type = root->children[0];
    astree* old_name = root->children[0]->children[0];
    string type = typemap(old_type);
    string name = name_mangle(old_name);
    if(!root->children[0]->children[0]->blk_nr)
        out<<type+" "+name+";"<<endl;
}
void alloc(ofstream& out,astree* root){
    astree* new_type =   root->children[0];
    switch(new_type->symbol){
        case TOK_NEW:
            out<<"struct "<< *new_type->lexinfo<<"*"
            <<reg_count++<< " = "
            <<"xcalloc (1, sizeof (struct "
            <<*new_type->lexinfo<< "));" << endl;
            break;
        case TOK_NEWSTRING:
            out<<"char* p"<<reg_count++<<" = "
            <<"xcalloc ("<<root->children[0]->lexinfo->length()
            <<", sizeof (char));"<<endl;
            break;
        case TOK_NEWARRAY:
            out<<typemap(root->children[0])<<"* p"<<reg_count++
            <<"xcalloc ("<<root->children[1]->lexinfo->length()
            <<", sizeof("<<typemap(root->children[0])
            <<"));"<<endl;
            break;
    } 
}
void operand(ofstream& out,astree* root){
    switch(root->symbol){
        case TOK_TRUE:
            out<<"1";
            break;
        case TOK_FALSE:
        case TOK_NULL:
            out<<"0";
            break;
        case TOK_IDENT:
            out<<" "+*root->lexinfo;
            break;
        case TOK_INDEX:
            exprs(out,root->children[0]);
            out<<"[";
            exprs(out,root->children[1]);
            out<<"]";
            break;
        case TOK_FIELD:
            exprs(out,root->children[0]);
            out<<".";
            exprs(out,root->children[1]);
            break;
        case TOK_INTCON:
        case TOK_CHARCON:
        case TOK_STRINGCON:
            out<<" "+*root->lexinfo;
            break;
    }
}
void gen_call(ofstream& out,astree* root){
    out<<name_mangle(root->children[0])<<" (";
    for(int i=1; i<root->children.size(); ++i){
        out<<name_mangle(root->children[i]);
        if(i!=root->children.size()-1)
            out<<",";
    }
    out<<")"<<endl;
}
void exprs(ofstream& out,astree* root){
    switch(root->symbol){
        case '=':
            gen_assign(out,root);
        case TOK_EQ:
        case TOK_NE:
        case TOK_LT:
        case TOK_LE:
        case TOK_GT:
        case TOK_GE:
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            binop_expr(out,root);
            break;
        case TOK_POS:
        case TOK_NEG:
        case '!':
        case TOK_ORD:
        case TOK_CHR:
            unop_expr(out,root);
            break;
        case TOK_NEW:
        case TOK_NEWSTRING:
        case TOK_NEWARRAY:
            alloc(out,root);
            break;
        case TOK_CALL:
            gen_call(out,root);
            break;
        case TOK_TRUE:
        case TOK_FALSE:
        case TOK_NULL:
        case TOK_IDENT:
        case TOK_INDEX:
        case TOK_FIELD:
        case TOK_INTCON:
        case TOK_CHARCON:
        case TOK_STRINGCON:
            operand(out,root);
            break;
    }

}


void gen_assign(ofstream& out,astree* root){
    if(root->children[0]->symbol == TOK_IDENT){
        /*symbol* get  =   search_symbol(symbol_stack, *root->children[0]->lexinfo);
        out<<get->attributes<<" filenr"<<endl;
        if(get != nullptr){
            out<<" here"<<endl;
            string type = get_type(get);
            out<<type<<endl;
            out<<type+" "+reg_var(type)+to_string(++reg_count);
            
            out<<" "+*root->lexinfo;
            exprs(out,root->children[1]);
            out<<";"<<endl;
            
            out<<name_mangle(root->children[0]->children[0]);
            out<<" "+*root->lexinfo+" ";
            out<<reg_var(type)+to_string(reg_count);        
         }*/    
        out<<name_mangle(root->children[0]);
        out<<" "+*root->lexinfo;
        exprs(out,root->children[1]);
        out<<";"<<endl;
    }
    else{ 
        cout<<*root->children[0]->lexinfo<<endl;
        out<<typemap(root->children[0])+" ";
        out<<name_mangle(root->children[0]->children[0]);
        out<<" "+*root->lexinfo;
        exprs(out,root->children[1]);
        out<<";"<<endl;
    }
}

void gen_if(ofstream& out,astree* root){
    condition_gen(out,root);
    out<< "if (!b" << reg_count+1 << ") "
        << "goto "<<(root->symbol == TOK_IFELSE)?"break_":"fi_";
    out<<to_string(root->filenr) +"_"
        + to_string(root->linenr) +"_"
        + to_string(root->offset) +";"<<endl;
    statements(out,root->children[1]);
    if(root->symbol == TOK_IFELSE){
        out<< "goto fi_";
        out<<to_string(root->filenr) +"_"
        + to_string(root->linenr) +"_"
        + to_string(root->offset) +";"<<endl;

        out<< "goto else_";
        out<<to_string(root->filenr) +"_"
        + to_string(root->linenr) +"_"
        + to_string(root->offset) +";"<<endl;
        statements(out,root->children[2]);
    }
    out<< "fi_";
    out<<to_string(root->filenr) +"_"
    + to_string(root->linenr) +"_"
    + to_string(root->offset) +";"<<endl;
}
void gen_return(ofstream& out,astree* root){
    out<<"return";
    if(root->children.size()){
        exprs(out,root->children[0]);
    }
    out<<";"<<endl;
}
void statements(ofstream& out,astree* root){
    switch(root->symbol){
        case TOK_BLOCK:
            for(auto child:root->children)
                statements(out,child);
            break;
        case '=':
            exprs(out,root);
            break;
        case TOK_WHILE:
            whiledecl(out,root);
            break;
        case TOK_IF:
        case TOK_IFELSE:
            gen_if(out,root);
            break;
        case TOK_RETURN:
        case TOK_RETURNVOID:
            gen_return(out,root); 
            break;
        case TOK_CALL:
            gen_call(out,root);
            break;
   }
}

void whiledecl(ofstream& out,astree* root){
    string new_label = keyword_mangle(root);
    out<<new_label+":;"<<endl;
    condition_gen(out,root->children[0]);
    out << "if (!b" << reg_count-1
        << ") goto break_"
        << to_string(root->filenr) << "_"
        << to_string(root->linenr) << "_"
        << to_string(root->offset)
        << ";" << endl;

    statements(out,root->children[1]);
    out << endl;
    out << "goto "+new_label<< endl;
    out << "break_"
         << to_string(root->filenr) << "_"
         << to_string(root->linenr) << "_"
         << to_string(root->offset)
         << ":" << endl;
}

void condition_gen(ofstream& out,astree* root){
    int size    =   root->children.size();
    out<<"char b"<<reg_count++<<" = ";
    if(size==2){
        out<<name_mangle(root->children[0])
            <<" "<<*root->lexinfo
            <<" "<<name_mangle(root->children[1])
            <<";"<<endl;
    }
    else if(size==1){
        out<<*root->lexinfo
            <<" "<<name_mangle(root->children[0])
            <<";"<<endl;
    }else{
        out<<*root->lexinfo
            <<";"<<endl;
    }
}

void binop_expr(ofstream& out,astree* root){
    astree* lchild  =   root->children[0]; 
    astree* rchild  =   root->children[1];
    exprs(out,lchild);
    out<<" "+*root->lexinfo;
    exprs(out,rchild);
}

void unop_expr(ofstream& out,astree* root){
    if(root->symbol == TOK_ORD){
        out<<"(int) " ;
    }else if(root->symbol == TOK_CHR){
        out<<"(char)" ;
    }else{
        out<<*root->lexinfo<<" ";
    }
    out<<name_mangle(root->children[0])<<endl;
}
string reg_var(string var_type){
    if(var_type == "char"){
        return "c";
    }
    if(var_type == "string"){
        return "s";
    }
    if(var_type == "int"){
        return "i";
    }
}

void funcdecl(ofstream& out,astree* root){
    astree* return_type    =   root->children[0];
    astree* func_name      =   return_type->children[0];
    string type            =   typemap(return_type);
    string name            =   name_mangle(func_name);
    out<<type+" "+name+" "+"("<<endl;
    astree* param          =   root->children[1];
    string ptype,pname;
    if(!param->children.size()){
        ptype    =   "void";
        out<<indent<<ptype<<")"<<endl;
    }
    else{ 
        for(int i=0; i < param->children.size(); ++i){
        astree* param_type  =   param->children[i];
        astree* param_name  =   param_type->children[0];
        ptype        =   typemap(param_type);
        pname        =   name_mangle(param_name);
        out<<indent<<ptype+" "+pname+(i == param->children.size()-1? ")":",")<<endl;
        }
    }
    out<<"{"<<endl;
    astree* block           =   root->children[2];
    for(auto child:block->children){    
        statements(out,child);
    }
}

void gencode(ofstream& out,astree* root){ 
    for(auto child:root->children)
        if(child->symbol == TOK_STRUCT)
            structdef(out,child);
        out<<" "<<endl;
    for(auto child:root->children)
        if(child->symbol == TOK_VARDECL && (child->children[1]->symbol == TOK_STRINGCON ))
            stringdef(out,child);
    for(auto child:root->children)
        if(child->symbol == TOK_VARDECL && (child->children[1]->symbol != TOK_STRINGCON )) 
            vardecl(out,child); 
        out<<" "<<endl;
    for(auto child:root->children)
        if(child->symbol == TOK_FUNCTION)
            funcdecl(out,child);
        out<<" "<<endl;
    out << "void __ocmain (void)" << endl << "{" << endl;
    for (astree* child: root->children) {
        if (child->symbol != TOK_FUNCTION && child->symbol != TOK_STRUCT && child->symbol != TOK_VARDECL)
            statements(out,child);
    }
    out << "}" << endl;
}


