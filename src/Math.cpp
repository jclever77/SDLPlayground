# include <Math.hpp>

Vector2f::Vector2f()
: x(0.0f), y(0.0f)
{
}

Vector2f::Vector2f(float x, float y)
: x(x), y(y)
{
}

Vector2f &Vector2f::operator+=(const Vector2f &rhs)
{
    x += rhs.x;
    y += rhs.y;
    
    return *this;
}

Vector2f operator+(Vector2f lhs, const Vector2f &rhs) { return lhs += rhs; }

Vector2f &Vector2f::operator*=(const float &rhs)
{
    x *= rhs;
    y *= rhs;
    
    return *this;
}

Vector2f operator*(Vector2f lhs, const float &rhs) { return lhs *= rhs; }

Vector2f &Vector2f::operator-=(const Vector2f &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    
    return *this;
}

Vector2f operator-(Vector2f lhs, const Vector2f &rhs) { return lhs -= rhs; }

Vector2f &Vector2f::operator/=(const float &rhs)
{
    x /= rhs;
    y /= rhs;
    
    return *this;
}

Vector2f operator/(Vector2f lhs, const float &rhs) { return lhs /= rhs; }

void Vector2f::Print() { std::cout << x << ", " << y << std::endl; }