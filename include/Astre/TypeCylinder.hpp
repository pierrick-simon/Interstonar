/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeCylinder
*/

#ifndef TYPECYLINDER_HPP
    #define TYPECYLINDER_HPP

#include "AType.hpp"

namespace inter {
    class TypeCylinder : public AType {
        public:
            TypeCylinder(double radius, int height)
                : _radius(radius), _height(height) {};
            ~TypeCylinder() {};

            bool isCollide(Vector3D vec) override {return false;}

        private:
            double _radius;
            int _height;
    };
}

#endif
