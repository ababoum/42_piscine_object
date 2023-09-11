#ifndef VECTOR2_HPP
#define VECTOR2_HPP

struct Vector2
{
private:
    float x;
    float y;

public:
    Vector2(float x, float y);
    Vector2(const Vector2 &other);
    Vector2 &operator=(const Vector2 &other);
    ~Vector2();

    float getX() const;
    float getY() const;
};

#endif