/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeBox
*/

#include <iostream>
#include "TypeBox.hpp"

void inter::TypeBox::print()
{
    std::cout << "Box of dimensions ";
    _sides.printVector(2, ", ");
}
