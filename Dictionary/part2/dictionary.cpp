#define _CRT_SECURE_NO_WARNINGS
#include "dictionary.h"
#include "word.h"
#include <iostream>

#include <fstream>
#include <sstream>

#include <map>
#include <vector>

namespace sdds {

    std::map<std::string, std::vector<WordDetails>> DICTIONARY;

	int LoadDictionary(const char* filename)
	{
        // open file
        std::ifstream dictionaryFile(filename);
        if (!dictionaryFile) return -1; // Couldn't open file ${filename}

        std::string id;

        std::string line;
        while (std::getline(dictionaryFile, line))
        {
            std::string word; // language
            WordDetails detail; // empty
            
            bool isType = true;

            for (char& character : line)
            {
                if (line[0] != '\t')
                {
                    // new word
                    word += character;
                }
                else
                {
                    // ignore '\t'
                    if (character == '\t') continue;

                    if (character == ':')
                    {
                        // now it is the definition
                        isType = false;
                        // ignore ':'
                        continue;
                    }

                    // insert data to the details
                    if (isType)
                        detail.type += character;
                    else
                        detail.definition += character;
                }
            }

            if (word != "")
            {
                id = word;
                // make new entry
                DICTIONARY.insert(std::make_pair(word, std::vector<WordDetails>()));
            }
            else
            {
                if (detail.type != "" && detail.definition != "")
                    DICTIONARY.at(id).push_back(detail);
            }
        }

        // close file handler
        dictionaryFile.close();
		return 0;
	}

    int UpdateDefinition(const char* word, const char* type, const char* definition)
    {
        std::string _word = word;
        std::string newType = type;
        std::string newDefinition = definition;


        if (DICTIONARY.find(_word) != DICTIONARY.end())
        {
            int updateIndex = 0;
            std::vector<WordDetails>& definitions = DICTIONARY.at(_word);
            
            if (definitions.size() > 1)
            {
                std::cout << "The word " << "[" << word << "] ";
                std::cout << "has [" << definitions.size() << "] definitions:\n";
                for (int i = 0; i < definitions.size(); i++)
                {
                    std::cout << i + 1 << ". ";
                    std::cout << "{" << definitions[i].type << "}";
                    std::cout << definitions[i].definition << std::endl;
                }

                std::cout << "Which one to update? ";
                std::cin >> updateIndex;
                updateIndex -= 1;

            }
            
            definitions[updateIndex].type = newType;
            definitions[updateIndex].definition = " " + newDefinition;
            return 0;
        }
        return -1;
        
    }

    void SaveDictionary(const char* filename)
    {
        std::ofstream newDictionaryFile(filename);

        // pair<string, vector<WordDetails>>
        
        for (auto& word : DICTIONARY)
        {
            newDictionaryFile << word.first << "\n";
            for (WordDetails& details : word.second)
            {
                newDictionaryFile << "\t" << details.type << ":" << details.definition << "\n";
            }
            newDictionaryFile << "\n";
        }

        newDictionaryFile.close();
    }
}
