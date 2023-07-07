#include "CogMaze.h"

#include <iostream>

CogMaze::CogMaze(const int key1, const int key2)
	: p(key1), q(key2)
{
	int r = -1;
	do
	{
		j++;
		r = p % q;
		p = q;
		q = r;

		// std::cout << "j: " << j << std::endl;
		// std::cout << "r: " << r << std::endl;
		// std::cout << "p: " << p << std::endl;
		// std::cout << "q: " << q << std::endl;

	} while (r != 0);
}
