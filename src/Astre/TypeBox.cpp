/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeBox
*/

#include <iostream>
#include <cmath>
#include "TypeBox.hpp"

void inter::TypeBox::print()
{
    std::cout << "Box of dimensions ";
    _sides.printVector(2, ", ");
}

double inter::TypeBox::sdfFunc(Vector3D point, Vector3D pos)
{
    auto diff = point - pos;

    Vector3D q(
        fabs(diff._x) - (_sides._x / 2.0),
        fabs(diff._y) - (_sides._y / 2.0),
        fabs(diff._z) - (_sides._z / 2.0)
    );
    Vector3D qMax(
        std::max(q._x, 0.0),
        std::max(q._y, 0.0),
        std::max(q._z, 0.0)
    );

    return sqrt(pow(qMax._x, 2) + pow(qMax._y, 2) + pow(qMax._z, 2))
        + std::min(std::max(q._x, std::max(q._y, q._z)), 0.0);

}