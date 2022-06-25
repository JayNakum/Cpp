#include <iostream>

class Entity
{
private:
    int *m_x, *m_y;
    mutable int var;

public:
    int *getX() const // cant modify class variables / read only method
    {
        var = 2;
        return m_x;
    }

    const int *const getY() const // pointer cant be modified, its content cant be modified and read only method
    {
        return m_y;
    }

    void setX(int *x)
    {
        m_x = x;
    }
};

void printEntity(const Entity& e) {
    std::cout << e.getX() << std::endl;
}

void test()
{
    const int *i = new int; // same as int const* i = new int;
    int *const j = new int;
    const int *const k = new int;

    int x = 8;
    auto f = [=]() mutable
    {
        x++; // requires mutable
        std::cout << x << std::endl; // requires [=] (pass by value) OR [&] (pass by reference)
    };

    f();
    // x = 8; because it is still pass by value

    std::cin.get();
}