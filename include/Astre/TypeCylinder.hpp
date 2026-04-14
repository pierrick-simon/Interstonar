/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeCylinder
*/

#ifndef TYPECYLINDER_HPP
    #define TYPECYLINDER_HPP

#include "IType.hpp"

namespace inter {
    class TypeCylinder : public IType {
        public:
            TypeCylinder(double radius, double height)
                : _radius(radius), _height(height), _inf(false) {};
            TypeCylinder(double radius)
                : _radius(radius), _inf(true) {};
            ~TypeCylinder() {};

            double getBounds() const override { return _radius; };
            double sdfFunc(Vector3D point, Vector3D pos) override;
            void print() override;

        private:
            double _radius;
            double _height;
            bool _inf;
    };
}

#endif
