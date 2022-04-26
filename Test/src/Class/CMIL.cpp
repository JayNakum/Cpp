#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_name;
    int m_score;

public:
    Entity()
        : m_name("Unknown"), m_score(0) // order of definition of variable matters
    {
    }

    Entity(const String &name)
        : m_name(name)
    {
    }

    const String &getName() const { return m_name; }
};

void test()
{

    Entity entity; // stack

    std::cin.get();
}