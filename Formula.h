#ifndef FORMULA_CLASS

#define matchingBrackets matchingParantheses
#define FORMULA_CLASS

#include <bits/stdc++.h>

using namespace std;

class formulaTree{
        public:
                static string matchingParantheses(string s);
                inline static bool openParantheses(string s){ return s=="("||s=="{"||s=="["; }
                inline static bool closeParantheses(string s){ return s==")"||s=="}"||s=="]"; };
                inline bool isUnary(string s){ return unary_precedence.find(s)!=unary_precedence.end(); }
                inline bool isBinary(string s){ return binary_precedence.find(s)!=binary_precedence.end(); }
                formulaTree(){
                }
                bool parse(string s);
                bool addUnaryOperator(string s, int p);
                bool addBinaryOperator(string s, int p);

        private:
                class tree{
                        public:
                                tree(string s){
                                        value = s;
                                }
                                std::vector<tree*> c;
                                string value;
                };
                tree* root;
        	map<string, int> unary_precedence; //For custom unary operators
        	map<string, int> binary_precedence; //For custom binary operators
};

#endif

