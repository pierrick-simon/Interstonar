/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeTorus
*/

#ifndef TYPETORUS_HPP
    #define TYPETORUS_HPP

#include "AType.hpp"

namespace inter {
    class TypeTorus : public AType {
        public:
            TypeTorus(double innerRadius, double outerRadius)
                : _innerRadius(innerRadius), _outerRadius(outerRadius) {};
            ~TypeTorus() {};

            bool isCollide(Vector3D vec) override {return false;}

        private:
            double _innerRadius;
            double _outerRadius;
    };
}

#endif
