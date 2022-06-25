#include <iostream>
#include <array>
#include <vector>

struct Vector3
{
    float x, y, z;
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z) {}
};

void test()
{
    static const int exampleSize = 5;
    int example[exampleSize];
    int *other = new int[5];

    other[1] = 0;

    for (int i = 0; i < exampleSize; i++)
    {
        example[i] = 0;
    }

    std::array<int, 5> another;
    std::cout << another.size() << std::endl;

    std::cout << example[0] << std::endl;
    std::cout << sizeof(example) / sizeof(int) << std::endl;
    std::cout << example << std::endl; // prints memory address

    std::vector<Vector3> vertices;
    vertices.reserve(2);
    // vertices.push_back(Vector3(1, 2, 3));
    // vertices.push_back(Vector3(4, 5, 6));
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 5, 6);

    vertices.erase(vertices.begin() + 1);

    std::cin.get();
}