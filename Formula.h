#ifndef FORMULA_CLASS
#define matching_brackets matching_parantheses
#define FORMULA_CLASS
#include <bits/stdc++.h>
using namespace std;
class formula_tree{
	class tree{
		std::vector<tree*> c;
	};
	map<string,int> unary_precedence; //For custom unary operators
	map<string,int> binary_precedence; //For custom binary operators
	public:
		static string matching_parantheses(string s);
		formula_tree();
		bool parse(string s);
		bool add_unary_operator(string s,int p);
		bool add_binary_operator(string s,int p);
};
#endif