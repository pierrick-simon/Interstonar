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
            TypeSphere(Vector3D sides) : _sides(sides) {};
            ~TypeSphere() {};

            bool isCollide(Vector3D vec) override {return false;}

        private:
            Vector3D _sides;
    };
}

#endif
