#pragma once

#include "CogMaze.h"

#include <string>
#include <vector>

class Application
{
public:
	Application(const std::string& executablePath, const int key1);
	~Application();
	void run(const std::string& nexePath);

private:
	std::string encrypt(const std::string& plainIns);
	std::string decrypt(const std::string& encryptedIns);

private:
	CogMaze* cipher;
	std::vector<std::string> m_asmCode;
	const int key2 = 329;
};
