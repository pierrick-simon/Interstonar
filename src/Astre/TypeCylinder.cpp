/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeCylinder
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "TypeCylinder.hpp"

void inter::TypeCylinder::print()
{
    std::cout << "Cylinder of radius "
        << std::fixed << std::setprecision(2) << _radius << " and ";
    if (_inf)
        std::cout << "infinite height";
    else
        std::cout << "height "
            << std::fixed << std::setprecision(2) << _height;
}

double inter::TypeCylinder::sdfFunc(Vector3D point, Vector3D pos)
{
    double dist = 0;
    auto diff = point - pos;

    if (_inf)
        dist = sqrt(pow(diff._x, 2) + pow(diff._y, 2)) - _radius;
    else {
        double radial = sqrt(pow(diff._x, 2) + pow(diff._y, 2)) - _radius;
        double axial  = fabs(diff._z) - (_height / 2.0);
        double radialMax = std::max(radial, 0.0);
        double axialMax  = std::max(axial,  0.0);

        dist = std::min(std::max(radial, axial), 0.0)
            + sqrt(pow(radialMax, 2) + pow(axialMax, 2));
    }
    return dist;
}

double inter::TypeCylinder::getBounds() const
{
    if (_inf)
        return std::numeric_limits<double>::max();
    return std::sqrt(_radius * _radius + (_height / 2.0) * (_height / 2.0));
}