#include "pch.h"
#include "LexicalAnalyzer.h"

int main()
{
	LexicalAnalyzer la;
    std::ifstream programFile("D:\\SSCD\\LexicalAnalyzer\\src\\Test.jay");
    
    if (!programFile)
    {
        std::cerr << "Cannot open the file: Test.jay" << std::endl;
        return -1;
    }
    
    std::list<std::string> tokens = la.splitTokens(programFile);

    std::cout << "Tokens count: " << tokens.size() << std::endl;
    
    for (auto token : tokens)
    {
        std::cout << token << std::endl;
    }

    programFile.close();
}
