#ifndef SPEC_CLASS

#define SPEC_CLASS

#include <iostream>
#include <assert.h>
#include <set>
#include <string>
#include <map>

// using namespace std;

class formulaSpec{
public:
	formulaSpec(){initialized_spec = false;}
	static int getHash(std::string s){int p = 257,mod=100003;int hash_value = 0;for(auto i:s){ hash_value += i * p;p *= 257;hash_value %= mod;p %= mod;};return hash_value;}
	inline int getArity(std::string s){return operator_list[getHash(s)].arity;}
	inline bool isEmpty(){ return !initialized_spec; }
	inline int getPrecedence(std::string e){ return operator_list[getHash(e)].precedence; }
	inline bool isVariable(std::string e){ return operator_list_set.find(e) == operator_list_set.end(); }
	bool addOperator(std::string s,int arity,int precedence);
private:
	bool initialized_spec;
	class operatorSpec{
	public:
		int precedence;
		int arity;
		operatorSpec(){precedence = arity = -1;}
	};
	operatorSpec operator_list[100003];
	std::set<std::string> operator_list_set;
};
#endif

