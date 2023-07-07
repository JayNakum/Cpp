#include "FileManager.h"

#include <fstream>
#include <iostream>

namespace FileManager
{
	// format-hex file.exe | more
	std::vector<std::string> read(const std::string& filePath, unsigned int lineCount)
	{
		std::vector<std::string> lines = std::vector<std::string>();
		lines.reserve(lineCount);

		std::ifstream file(filePath);
		if (file.is_open())
		{
			std::string line;
			while (std::getline(file, line)) lines.push_back(line);
		}
		else
		{
			std::cerr << "FILE ERROR [could not read] : " << filePath << std::endl;
		}

		file.close();
		return lines;
	}

	void write(const std::vector<std::string>& data, const std::string& filePath)
	{
		std::ofstream file(filePath);
		if (file.is_open())
		{
			for (auto& line : data) file << line << std::endl;
		}
		else
		{
			std::cerr << "FILE ERROR [could not write] : " << filePath << std::endl;
		}
		file.close();
	}
}
