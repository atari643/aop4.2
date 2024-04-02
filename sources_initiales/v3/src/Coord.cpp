#include <cmath>

#include "Coord.h"
using namespace std; // l'espace de nom standard contient un grnad nombre de fonctionnalités 

Coord::Coord()
{
    this->x = 0;
    this->y = 0;
}

Coord::Coord(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Coord::norm() const
{
    float origin_X=0;
    float origin_Y=0;
    return sqrt(pow(this->x - origin_X, 2) + pow(this->y - origin_Y, 2));
}

bool Coord::operator==(const Coord &c) const 
{
    return this->x == c.x && this->y == c.y;
}

Coord Coord::operator+(const Coord &c) const 
{
    return Coord(this->x + c.x, this->y + c.y);
}

Coord Coord::operator-(const Coord &c) const 
{
    return Coord(this->x - c.x, this->y - c.y);
}

Coord& Coord::operator+=(const Coord &c)
{
    return *this = *this + c;
}

Coord& Coord::operator-=(const Coord &c)
{
    return *this = *this - c;
}

Coord Coord::operator*(const float &f) const 
{
    return Coord(this->x * f, this->y * f);
}

Coord Coord::operator/(const float &f) const
{
    return Coord(this->x / f, this->y / f);
}

Coord& Coord::operator*=(const float &f)
{
    return *this = *this * f;
}

Coord& Coord::operator/=(const float &f)
{
    return *this = *this / f;
}

float Coord::operator[](int dim) const
{
    return dim == 0 ? this->x : this->y;
}

float & Coord::operator[](int dim)
{
    return dim == 0 ? this->x : this->y;
}