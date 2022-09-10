#include "pch.h"
#include "TokenCounter.h"

TokenCounter::TokenCounter()
{
    initTokens();
}

std::list<std::string> TokenCounter::splitTokens(std::ifstream& srcFile)
{
    std::list<std::string> tokens;

    std::string line;
    std::string token;
    while (std::getline(srcFile, line))
    {
        bool isString = false;
        bool isComment = false;
        for (char chr : line)
        {
            if (chr == '"') isString = !isString;
            if (chr == '#') isComment = !isComment;

            if (chr == ' ' && !isString && !isComment)
            {
                if(token == "") continue;
                tokens.push_back(token);
                token = "";
            }
            else if (std::find(m_symbols.begin(), m_symbols.end(), std::string(1, chr)) != m_symbols.end() && !isString)
            {
                if (token != "") tokens.push_back(token);
                tokens.push_back(std::string(1, chr));
                token = "";
            }
            else
            {
                token += chr;
            }
        }
    }
    return tokens;
}

void TokenCounter::initTokens()
{
    enum class TokenType
    {
        NONE = -1,
        DATATYPES = 0,
        KEYWORDS = 1,
        SYMBOLS = 2,
    };
        
    std::ifstream tokensFile("src\\tokens.sscd");
    if (!tokensFile)
    {
        std::cerr << "Cannot open the file: tokens.sscd" << std::endl;
        return;
    }

    TokenType tokenType = TokenType::NONE;
    std::string token;
    while (std::getline(tokensFile, token))
    {
        if (token.size() > 0)
        {
            if (token.find("#") != std::string::npos)
            {
                if (token.find("keywords") != std::string::npos)
                    tokenType = TokenType::KEYWORDS;
                else if (token.find("datatypes") != std::string::npos)
                    tokenType = TokenType::DATATYPES;
                else if (token.find("symbols") != std::string::npos)
                    tokenType = TokenType::SYMBOLS;
            }
            else 
            {
                switch (tokenType)
                {
                case TokenType::DATATYPES:
                    m_datatypes.emplace_back(token);
                    break;
                case TokenType::KEYWORDS:
                    m_keywords.emplace_back(token);
                    break;
                case TokenType::SYMBOLS:
                    m_symbols.emplace_back(token);
                    break;
                }
            }
        }
    }
    tokensFile.close();
}
