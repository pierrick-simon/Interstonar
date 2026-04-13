/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Astre
*/

#include <iostream>
#include "Astre.hpp"

void inter::Astre::print()
{
    _type->print();
    std::cout << " at position ";
    _pos.printVector(2, ", ");
    std::cout << std::endl;
}

void inter::Astre::reset()
{
    _name = std::string();
    _pos = Vector3D();
    _velocity = Vector3D();
    _mass = double();
    _type.reset();
}

void inter::Astre::move(double dist)
{
    auto normalize = _velocity.getNormalize();

    if (normalize == 0)
        return;
    auto x = _pos._x + dist * _velocity._x / normalize;
    auto y = _pos._y + dist * _velocity._y / normalize;
    auto z = _pos._z + dist * _velocity._z / normalize;
    _pos = {x, y, z};
}