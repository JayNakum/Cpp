#define _CRT_SECURE_NO_WARNINGS
#include "word.h"

#include <iostream>
#include <map>
#include <vector>

namespace sdds {

    extern std::map<std::string, std::vector<WordDetails>> DICTIONARY;

    void DisplayWord(const char* word)
    {
        std::string _word = word;

        if (DICTIONARY.find(_word) != DICTIONARY.end())
        {
            std::vector<WordDetails>& definitions = DICTIONARY.at(_word);
            std::cout << "FOUND: ";
            std::cout << "[" << word << "] ";
            std::cout << "has [" << definitions.size() << "] definitions:\n";

            for (int i = 0; i < definitions.size(); i++)
            {
                std::cout << i + 1 << ". ";
                std::cout << "{" << definitions[i].type << "}";
                std::cout << definitions[i].definition << std::endl;
            }
        }
        else
        {
            std::cout << "NOT FOUND: word [" << _word << "] is not in the dictionary." << std::endl;
        }
    }

    void AddWord(const char* word, const char* type, const char* definition)
    {
        std::string newWord = word;
        std::string newType = type;
        std::string newDefinition = definition;

        WordDetails details = { newType, " " + newDefinition };


        if (DICTIONARY.find(newWord) != DICTIONARY.end())
        {
            DICTIONARY.at(newWord).push_back(details);
        }
        else
        {
            std::vector<WordDetails> definitions;
            definitions.push_back(details);
            DICTIONARY.insert(std::make_pair(newWord, definitions));
        }
    }
}
