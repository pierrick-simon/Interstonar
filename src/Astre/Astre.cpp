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

inter::Vector3D inter::Astre::getForce(const Astre &astre) const
{
    double n = this->getPos().getNorm(astre.getPos());
    if (n == 0)
        return Vector3D();
    Vector3D f = Vector3D(this->getPos(), astre.getPos()) *
        ((G * this->getMass() * astre.getMass()) / ( n * n * n));
    return f;
}

void inter::Astre::applyForce(const Vector3D &force, const std::size_t &dt)
{
    Vector3D a = force / this->getMass();
    Vector3D v = getVelocity();
    Vector3D vAfter = v + (a * dt);
    Vector3D posAfter = getPos() + (v * dt);

    setPos(posAfter);
    setVelocity(vAfter);
}
