#include "pch.h"
#include "TokenCounter.h"

int main()
{
	TokenCounter la;
    std::ifstream programFile("Test.jay");
    
    if (!programFile)
    {
        std::cerr << "Cannot open the file: Test.jay" << std::endl;
        return -1;
    }
    
    std::list<std::string> tokens = la.splitTokens(programFile);
    std::cout << "Total Tokens: " << tokens.size() << std::endl;

    std::map<std::string, int> tokenCount;
    for (auto& token : tokens)
    {
        // std::cout << token << std::endl;
        if (tokenCount.find(token) == tokenCount.end())
            tokenCount.insert(std::pair<std::string, int>(token, 1));
        else
            tokenCount.at(token)++;
    }
    for (auto& token : tokenCount) 
        std::cout << token.first << " : " << token.second << std::endl;

    programFile.close();
}
