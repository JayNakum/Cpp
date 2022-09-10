#pragma once

class TokenCounter
{
public:
	TokenCounter();

	std::list<std::string> splitTokens(std::ifstream&);

private:
	void initTokens();

	std::list<std::string> m_keywords;
	std::list<std::string> m_datatypes;
	std::list<std::string> m_symbols;
};

