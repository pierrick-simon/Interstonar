/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Vector3D
*/

#include <iostream>
#include <iomanip>
#include <locale>
#include <cmath>
#include "Vector3D.hpp"

void inter::Vector3D::printVector()
{
    std::cout << "(" << _x
        << " " << _y
        << " " << _z
        << ")";
}

void inter::Vector3D::printVector(std::size_t precision, std::string sep)
{
    std::cout << "(" << std::fixed << std::setprecision(precision) << _x
        << sep << std::fixed << std::setprecision(precision) << _y
        << sep << std::fixed << std::setprecision(precision) << _z
        << ")";
}

void inter::Vector3D::printVector(std::size_t precision, std::string sep, 
    std::string local)
{
    std::locale prevLocale = std::cout.getloc();
    std::cout.imbue(std::locale(local));
    std::cout << "(" << std::fixed << std::setprecision(precision) << _x
        << sep << std::fixed << std::setprecision(precision) << _y
        << sep << std::fixed << std::setprecision(precision) << _z
        << ")";
    std::cout.imbue(prevLocale);
}

double inter::Vector3D::getNorm(Vector3D vec)
{

    auto mul = vec - (*this);

    mul = mul * mul;
    return sqrt(mul._x + mul._y + mul._z);
}

double inter::Vector3D::getNormalize() const
{

    auto mul = (*this);

    mul = mul * mul;
    return sqrt(mul._x + mul._y + mul._z);
}