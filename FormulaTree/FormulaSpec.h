#ifndef SPEC_CLASS

#define SPEC_CLASS

#include <iostream>
#include <assert.h>
#include <set>
#include <string>
#include <map>

using namespace std;

class formulaSpec{
        public:
                inline int getArity(string s){return operator_list[s[0]].arity;}
                inline bool isEmpty(){ bool b = 0; for(int i=0;i<256;i++){b |= operator_list[i].arity!=-1;} return !b; }
                inline int getPrecedence(string e){ return operator_list[e[0]].precedence; }
                inline bool isVariable(string e){ return operator_list_set.find(e) == operator_list_set.end(); }
                bool addOperator(string s,int arity,int precedence,int associativity);
        private:
                class operatorSpec{
                public:
                        int precedence;
                        int arity;
                        int associativity;
                        operatorSpec(){precedence = arity = associativity = -1;}
                };
                operatorSpec operator_list[256];
                set<string> operator_list_set;
};
#endif

