#ifndef SPEC_CLASS

#define SPEC_CLASS

#include <iostream>
#include <string>
#include <map>

using namespace std;

class formulaSpec{
	public:

		inline bool isUnary(string s){ return unary_precedence.find(s)!=unary_precedence.end(); }
                inline bool isBinary(string s){ return binary_precedence.find(s)!=binary_precedence.end(); }
                inline bool isEmpty(){ return unary_precedence.size()==0 && binary_precedence.size()==0; }
                inline int getUPrecedence(string e){ return unary_precedence[e]; }
                inline int getBPrecedence(string e){ return binary_precedence[e]; }
                inline bool isVariable(string e){ return !unary_precedence.count(e) && !binary_precedence.count(e); }
                bool addUnaryOperator(string s, int p);
                bool addBinaryOperator(string s, int p);


        private:

        	map<string, int> unary_precedence; //For custom unary operators
        	map<string, int> binary_precedence; //For custom binary operators
};

#endif

