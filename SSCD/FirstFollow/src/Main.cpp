#include "Grammar.h"

#include <iostream>

int main()
{
	Grammar g;

	std::cout << "Terminals: {";
	for (auto& x : g.getTerminals())
	{
		std::cout << x << ", ";
 	}
	std::cout << "}" << std::endl;


	std::cout << "NonTerminals: {";
	for (auto& x : g.getNonTerminals())
	{
		std::cout << x << ", ";
	}
	std::cout << "}" << std::endl;


	std::cout << "Grammar:" << std::endl;
	for (auto& p : g.getProductions())
	{
		std::cout << p.left << " -> " << p.right << std::endl;
	}

}