#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(const Vector2 &other) : x(other.x), y(other.y) {}

Vector2 &Vector2::operator=(const Vector2 &other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Vector2::~Vector2() {}

float Vector2::getX() const
{
    return x;
}

float Vector2::getY() const
{
    return y;
}