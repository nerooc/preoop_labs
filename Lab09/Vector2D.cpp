#include "Vector2D.h"
#include <iostream>
#include <iomanip>


int Vector2D::count = 0;

Vector2D Vector2D::add(const Vector2D& vector) const{
    return Vector2D::fromCarthesian(_x + vector._x, _y + vector._y);
}

double Vector2D::dot(const Vector2D& vector) const{
    return (_x*vector._x + _y*vector._y);
}

void Vector2D::print(std::string napis) const{

    std::cout << napis << "(" << _x << ", " << _y << ")" << std::endl;
}
