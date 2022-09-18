#pragma once

namespace sdds {
	int LoadDictionary(const char* filename);
	int UpdateDefinition(const char* word, const char* type, const char* definition);
	void SaveDictionary(const char* filename);
};
