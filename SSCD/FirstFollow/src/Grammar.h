#pragma once

#include <string>
#include <set>
#include <vector>
#include <unordered_map>

struct Production 
{
	std::string left;
	std::vector<std::string> right;
};

class Grammar 
{
public:
	Grammar();
	~Grammar();

private:
	std::set<std::string> m_terminals;
	std::set<std::string> m_nonTerminals;
	std::vector<Production> m_productionOrder;
	std::unordered_map<std::string, std::vector<std::string>> m_productions;
};
