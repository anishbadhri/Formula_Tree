#ifndef FORMULA_CLASS

#define matchingBrackets matchingParantheses
#define FORMULA_CLASS

#include <sstream>
#include <vector>
#include <stack>
#include "FormulaSpec.cpp"

class formulaTree{
        public:
                formulaTree(){}
                formulaTree(formulaSpec sp){
                        spec=sp;
                }

                static string matchingParantheses(string s);
                inline static bool openParantheses(string s){ return s=="("||s=="{"||s=="["; }
                inline static bool closeParantheses(string s){ return s==")"||s=="}"||s=="]"; };
                bool parse(string s);


        protected:
                class tree{
                        public:
                                tree(string s){
                                        value = s;
                                }
                                std::vector<tree*> c;
                                string value;
                };
                tree *root;
                formulaSpec spec;
};

#endif

