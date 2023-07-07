#pragma once

#include <string>
#include <vector>

namespace FileManager
{
	std::vector<std::string> read(const std::string& filePath, unsigned int lineCount = 0);
	void write(const std::vector<std::string>& data, const std::string& filePath = "res\\executable.nexe");
}
