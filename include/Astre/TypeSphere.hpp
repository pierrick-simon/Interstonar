/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeSphere
*/

#ifndef TYPESPHERE_HPP
    #define TYPESPHERE_HPP

#include "AType.hpp"

namespace inter {
    class TypeSphere : public AType {
        public:
            TypeSphere(double radius) : _radius(radius) {};
            ~TypeSphere() {};

            bool isCollide(Vector3D vec) override {return false;}

        private:
            double _radius;
    };
}

#endif
