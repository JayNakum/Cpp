#include <iostream>

#include <string>
#include <fstream>
#include <sstream>

#include <map>

#include <algorithm>

int main() 
{

	std::ifstream programFile("src\\test.txt");
    if (!programFile)
    {
        std::cerr << "Cannot open the file: test.txt" << std::endl;
        return -1;
    }

    std::ifstream operatorsFile("src\\operators.sscd");
    if (!operatorsFile)
    {
        std::cerr << "Cannot open the file: operators.sscd" << std::endl;
        return -1;
    }

    std::map<std::string, int> operatorsCount;
    std::string op;
    while (std::getline(operatorsFile, op))
        operatorsCount.insert(std::pair<std::string, int>(op, 0));

    std::string line;
    while (std::getline(programFile, line))
    {
        for (auto i = 0 ; i < line.length() ; i++)
        {
            std::string lookAhead = "";
            lookAhead += line[i + 1];

            std::string c = "";
            c += line[i];

            if (operatorsCount.find(c) != operatorsCount.end() && operatorsCount.find(lookAhead) != operatorsCount.end()) {
                c += lookAhead;
                i++;
            }

            if (operatorsCount.find(c) != operatorsCount.end())
                operatorsCount.at(c)++;
        }
    }

    for (auto& o : operatorsCount) {
        std::cout << o.first << " : " << o.second << std::endl;
    }
}