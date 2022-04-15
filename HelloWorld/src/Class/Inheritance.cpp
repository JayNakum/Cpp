#include <iostream>

class Entity
{
public:
    float x, y;

    void move(float xa, float ya)
    {
        x += xa;
        y += ya;
    }
};

class Player : public Entity
{
public:
    char* name;

    void printName()
    {
        std::cout << name << std::endl;
    }
};

void test()
{
    Player player;
    player.move(1, -1);
    player.printName();

    std::cin.get();
}