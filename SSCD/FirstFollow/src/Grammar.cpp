#include "Grammar.h"

#include <iostream>
#include <fstream>

Grammar::Grammar()
{
	std::ifstream inputFile("InputGrammar.txt");
	if (!inputFile.is_open())
	{
		std::cerr << "Unable to open input file" << std::endl;
		return;
	}

	std::string line;
	bool terminals = false;
	bool nonterminals = false;

	while (std::getline(inputFile, line))
	{
		if (line == "") continue;

		if (!terminals)
		{
			for (char& c : line)
			{
				if (c == '{' || c == '}' || c == ',') continue;
				m_terminals.insert(c);
			}
			terminals = true;
		}

		if (!nonterminals)
		{
			for (char& c : line)
			{
				if (c == '{' || c == '}' || c == ',') continue;
				m_nonTerminals.insert(c);
			}
			nonterminals = true;
		}

		Production prod;
		bool isRight = false;
		for (size_t i = 0 ; i < line.length() ; i++)
		{	
			if (line[i] == ' ') continue;

			if (line[i] == '-' && line[i + 1] == '>')
			{
				isRight = true;
				i++;
				continue;
			}
			else if (line[i] == '|')
			{
				isRight = true;
				continue;
			}

			if (!isRight)
			{
				prod.left += line[i];
			}
			else
			{
				prod.right += line[i];
			}
		}
		m_productions.push_back(prod);
	}
}

Grammar::~Grammar()
{
	m_terminals.clear();
	m_nonTerminals.clear();
	m_productions.clear();
}
