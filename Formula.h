#ifndef FORMULA_CLASS

#define matching_brackets matching_parantheses
#define FORMULA_CLASS

#include <bits/stdc++.h>

using namespace std;

class formulaTree{
	public:
		static string matchingParantheses(string s);
		formulaTree(){

		}
		bool parse(string s);
		bool addUnaryOperator(string s, int p);
		bool addBinaryOperator(string s, int p);

	private:
		class tree{
			std::vector<tree*> c;
		};
		map<string, int> unary_precedence; //For custom unary operators
		map<string, int> binary_precedence; //For custom binary operators
};

#endif

