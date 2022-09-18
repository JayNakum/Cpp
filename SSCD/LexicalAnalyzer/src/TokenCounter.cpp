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
        int lookAheadPointer = 1;
        bool isString = false;
        bool isComment = false;
        bool next = false;
        for (char& chr : line)
        {
            if (next) { next = false; continue; }
            if (chr == '#')
            {
                isComment = !isComment;
                if (isComment && !isString) break;
            }
            if (chr == '"')
            {
                isString = !isString;
            }

            if (chr == ' ' && !isString && !isComment)
            {
                if (token == "")
                {
                    lookAheadPointer++;
                    continue;
                }
                tokens.push_back(token);
                token = "";
            }
            else if (std::find(m_symbols.begin(), m_symbols.end(), std::string(1, chr)) != m_symbols.end() && !isString)
            {
                std::string symbol = std::string(1, chr);
                if (token != "") tokens.push_back(token);
                if ((chr == '+' && (line[lookAheadPointer] == '=' || line[lookAheadPointer] == '+')) ||
                    (chr == '-' && (line[lookAheadPointer] == '=' || line[lookAheadPointer] == '-')) ||
                    (chr == '>' && line[lookAheadPointer] == '=') ||
                    (chr == '<' && line[lookAheadPointer] == '=') ||
                    (chr == '=' && line[lookAheadPointer] == '=')
                    )
                {
                    symbol += line[lookAheadPointer];
                    next = true;
                }
                tokens.push_back(symbol);
                token = "";
            }
            else
            {
                token += chr;
            }
            lookAheadPointer++;
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
