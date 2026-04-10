/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeSphere
*/

#include <iostream>
#include <iomanip>
#include "TypeSphere.hpp"

void inter::TypeSphere::print()
{
    std::cout << "Sphere of radius "
        << std::fixed << std::setprecision(2) << _radius;
}

double inter::TypeSphere::sdfFunc(Vector3D point, Vector3D pos)
{
    return point.getNorm(pos) - _radius;
}