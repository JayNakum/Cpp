#include <iostream>

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 multiply(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    // operator overloading
    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator*(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector2 &vector)
{
    stream << vector.x << ", " << vector.y;
    return stream;
}

void test()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result1 = position.add(speed.multiply(powerup));

    Vector2 result2 = position + speed * powerup;

    std::cin.get();
}