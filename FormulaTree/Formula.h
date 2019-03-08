#ifndef FORMULA_CLASS

#define matchingBrackets matchingParantheses
#define FORMULA_CLASS

#include <sstream>
#include <vector>
#include <algorithm>
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
                string printWalk(){ string s = printWalk(root); return s;};
                // bool compressTree();
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
                formulaSpec spec;
                string printWalk(tree* cur);
                
                // bool assignSubtreeExpression(tree* cur);
                // bool constructFormulaDAG(tree* cur);
                // map<string,tree*> subtree_hash;
};

#endif

