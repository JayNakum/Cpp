#include <iostream>
#include <string>
#include <memory>

using String = std::string;

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void print() {}
};

void test()
{
    {
        // std::unique_ptr<Entity> entity(new Entity());
        // entity->print();

        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    }

    {
        std::shared_ptr<Entity> sharedEntity1 = std::make_shared<Entity>();
        {
            std::shared_ptr<Entity> sharedEntity2 = std::make_shared<Entity>();
            std::weak_ptr<Entity> weakEntity = sharedEntity2;
            sharedEntity1 = sharedEntity2;
        }
    }

    std::cin.get();
}