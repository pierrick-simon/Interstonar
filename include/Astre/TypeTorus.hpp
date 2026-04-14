/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeTorus
*/

#ifndef TYPETORUS_HPP
    #define TYPETORUS_HPP

#include "IType.hpp"

namespace inter {
    class TypeTorus : public IType {
        public:
            TypeTorus(double innerRadius, double outerRadius)
                : _innerRadius(innerRadius), _outerRadius(outerRadius) {};
            ~TypeTorus() {};

            double getBounds() const override { return _outerRadius; };
            double sdfFunc(Vector3D point, Vector3D pos) override;
            void print() override;

        private:
            double _innerRadius;
            double _outerRadius;
    };
}

#endif
