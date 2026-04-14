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

            bool isCollide(Vector3D pos, Vector3D rockPos) override
                { return (pos.getNorm(rockPos) <= _radius); };
            double sdfFunc(Vector3D point, Vector3D pos) override;
            void print() override;

        private:
            double _radius;
    };
}

#endif
