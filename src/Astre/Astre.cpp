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