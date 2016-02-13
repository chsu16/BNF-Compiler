#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include "auxlib.h"
#include "./symbol-table-code.h"

using namespace std;


struct astree {
   int symbol;               // token code
   size_t filenr;            // index into filename stack
   size_t linenr;            // line number from source code
   size_t offset;            // offset of token with current line
   const string* lexinfo;          // pointer to lexical information
   vector<astree*> children; // children of this n-way node
   attr_bitset attr;
   int blk_nr;
   int reg_nr;
   astree (int symbol, int filenr, int linenr,
           int offset, const char* clexinfo);
};

// Append one child to the vector of children.
astree* adopt1 (astree* root, astree* child);

// Append two children to the vector of children.
astree* adopt2 (astree* root, astree* left, astree* right);

// Append three children to the vector of children.
astree* adopt3 (astree* root, astree* first, astree* second, astree* third);

//swap symbol to token code
void swap(astree* node, int tok_code);

// Dump an astree to a FILE.
void dump_astree (FILE* outfile, astree* root);

// Debug print an astree.
void yyprint (FILE* outfile, unsigned short toknum,
              astree* yyvaluep);

// Recursively free an astree.
void free_ast (astree* tree);

// Recursively free two astrees.
void free_ast2 (astree* tree1, astree* tree2);

RCSH("$Id: astree.h,v 1.4 2015-04-09 19:31:47-07 - - $")
#endif
