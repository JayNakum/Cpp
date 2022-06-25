#include<iostream>

struct Entity
{
    static int x, y;

    static void print() {
        std::cout << x << ", " << y << std::endl;
    }
};

void test() {
    Entity::x = 10;
    Entity::y = 5;

    Entity::print();
}