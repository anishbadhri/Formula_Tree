#ifndef FORMULA_CLASS

#define matchingBrackets matchingParantheses
#define FORMULA_CLASS

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class formulaTree{
        public:
                formulaTree(){
                }
                static string matchingParantheses(string s);
                inline static bool openParantheses(string s){ return s=="("||s=="{"||s=="["; }
                inline static bool closeParantheses(string s){ return s==")"||s=="}"||s=="]"; };
                inline bool isUnary(string s){ return unary_precedence.find(s)!=unary_precedence.end(); }
                inline bool isBinary(string s){ return binary_precedence.find(s)!=binary_precedence.end(); }
                bool parse(string s);
                bool addUnaryOperator(string s, int p);
                bool addBinaryOperator(string s, int p);

        protected:
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

