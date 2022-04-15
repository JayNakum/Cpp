#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string getClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string getName()
    {
        return "Entity";
    }
    std::string getClassName() override { return "Entity"; }
};

class Player : public Entity //, Printable
{
private:
    std::string m_name;

public:
    Player(const std::string name) : m_name(name) {}

    // cpp 11
    std::string getName() override { return m_name; }

    std::string getClassName() override { return "Player"; }
};

void printName(Entity *entity)
{
    std::cout << entity->getName() << std::endl;
}

void print(Printable *obj)
{
    std::cout << obj->getClassName() << std::endl;
}

void test()
{
    Entity *e = new Entity();
    printName(e);
    print(e);
    Player *p = new Player("Cherno");
    printName(p);
    print(p);
}