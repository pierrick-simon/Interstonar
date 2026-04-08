/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeSphere
*/

#ifndef TYPESPHERE_HPP
    #define TYPESPHERE_HPP

#include "IType.hpp"

namespace inter {
    class TypeSphere : public IType {
        public:
            TypeSphere(double radius) : _radius(radius) {};
            ~TypeSphere() {};

            bool isCollide(Vector3D vec) override {return false;}
            void print() override;

        private:
            double _radius;
    };
}

#endif
