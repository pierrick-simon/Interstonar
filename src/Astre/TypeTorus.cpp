/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeTorus
*/

#include <iostream>
#include <iomanip>
#include "TypeTorus.hpp"

void inter::TypeTorus::print()
{
    std::cout << "Torus of inner radius "
        << std::fixed << std::setprecision(2) << _innerRadius
        <<  " and outer radius "
        << std::fixed << std::setprecision(2) << _outerRadius;
}
