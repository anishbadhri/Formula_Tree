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
		formulaTree(){

		}
		bool parse(string s);
		bool addUnaryOperator(string s, int p);
		bool addBinaryOperator(string s, int p);

	private:
		class tree{
                        public:
			     std::vector<tree*> c;
		};
                tree* root;
		map<string, int> unary_precedence; //For custom unary operators
		map<string, int> binary_precedence; //For custom binary operators
};

#endif

