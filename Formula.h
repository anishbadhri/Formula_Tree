#ifndef FORMULA_CLASS

#define matchingBrackets matchingParantheses
#define FORMULA_CLASS

#include <sstream>
#include <vector>
#include <stack>
#include "FormulaSpec.h"

class formulaTree{
        public:
                formulaTree(){}
                formulaTree(formulaSpec sp){
                        spec=sp;
                }

                //Construction Operations
                static string matchingParantheses(string s);
                inline static bool openParantheses(string s){ return s=="("||s=="{"||s=="["; }
                inline static bool closeParantheses(string s){ return s==")"||s=="}"||s=="]"; };
                bool parse(string s);

                //Test Operations
                string inOrder(){ string s = inOrder(root); return s; }
                bool compressTree();
        protected:
                class tree{
                        public:
                                tree(string s){
                                        value = s;
                                        subtree_expression = s;
                                }
                                std::vector<tree*> c;
                                string value;
                                string subtree_expression;
                };
                tree *root;
                string inOrder(tree* cur);
                formulaSpec spec;
                bool assignSubtreeExpression(tree* cur);
                bool constructFormulaDAG(tree* cur);
                bool deleteRecursive(tree* cur);
                map<string,tree*> subtree_hash;
};

#endif

