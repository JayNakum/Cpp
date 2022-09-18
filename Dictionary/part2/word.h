#pragma once
#include <string>

namespace sdds {
	
	struct WordDetails
	{
		std::string type; // noun, verb, etc
		std::string definition; // definition
	};

	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
}
