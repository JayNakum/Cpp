#include "Application.h"

#include "utility/FileManager.h"

#include <thread>
#include <iostream>

Application::Application(const std::string& executablePath, const int key1)
{
	std::thread generateJ([&]() {
		cipher = new CogMaze(key1, key2);
	});

	m_asmCode = FileManager::read(executablePath);

	generateJ.join();
	std::vector<std::string> nexe = std::vector<std::string>();
	for (auto& line : m_asmCode)
		nexe.push_back(encrypt(line));
	FileManager::write(nexe);
}

Application::~Application()
{
	delete cipher;
}

void Application::run(const std::string& nexePath)
{
	// implement new hardware

	std::vector<std::string> encryptedASM = FileManager::read("res\\executable.nexe");
	for (auto& instruction : encryptedASM)
	{
		std::cout << "Executing:\n" << decrypt(instruction) << std::endl << std::endl;
	}
}

// cogMaze cipher
std::string Application::encrypt(const std::string& plainIns)
{
	std::string encryptedIns = "";

	for (char i : plainIns)
		encryptedIns += i - cipher->getJ() - cipher->getJ();

	return encryptedIns;
}

std::string Application::decrypt(const std::string& encryptedIns)
{
	std::string decryptedIns = "";

	for (char i : encryptedIns)
		decryptedIns += i + cipher->getJ() + cipher->getJ();

	return decryptedIns;
}
