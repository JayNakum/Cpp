#pragma once

class CogMaze
{
public:
	CogMaze(const int key1, const int key2);

	inline unsigned int getJ() const { return j; }

private:
	int p = 0;
	int q = 0;
	unsigned int j = 0;
};