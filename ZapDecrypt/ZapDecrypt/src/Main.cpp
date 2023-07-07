#include "Application.h"

int main()
{
	Application* zapDecrypt = new Application("res\\executable.txt", 2180);

	zapDecrypt->run("res\\executable.nexe");

	delete zapDecrypt;
}
