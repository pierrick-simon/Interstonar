/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeCylinder
*/

#include <iostream>
#include <iomanip>
#include "TypeCylinder.hpp"

void inter::TypeCylinder::print()
{
    std::cout << "Cylinder of radius "
        << std::fixed << std::setprecision(2) << _radius << " and ";
    if (_inf)
        std::cout << "infinite heigh";
    else
        std::cout << "height "
            << std::fixed << std::setprecision(2) << _height;
}
