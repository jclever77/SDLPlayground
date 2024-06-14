# pragma once

# include <iostream>

struct Vector2f
{
    float x, y;

    Vector2f();
    Vector2f(float x, float y);

    Vector2f &operator+=(const Vector2f &rhs);
    friend Vector2f operator+(Vector2f lhs, const Vector2f &rhs);

    Vector2f &operator*=(const float &rhs);
    friend Vector2f operator*(Vector2f lhs, const float &rhs);

    Vector2f &operator-=(const Vector2f &rhs);
    friend Vector2f operator-(Vector2f lhs, const Vector2f &rhs);
    
    Vector2f &operator/=(const float &rhs);
    friend Vector2f operator/(Vector2f lhs, const float &rhs);

    void Print();
};