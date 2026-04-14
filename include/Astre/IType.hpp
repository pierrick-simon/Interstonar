/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** IType
*/

#ifndef ITYPE_HPP
    #define ITYPE_HPP

#include <memory>
#include "Vector3D.hpp"

namespace inter {

    enum class Type {
        Sphere,
        Cylinder,
        Box,
        Torus,
    };

    class IType {
        public:
            virtual ~IType() = default;

            virtual double getBounds() const = 0;
            virtual double sdfFunc(Vector3D point, Vector3D pos) = 0;
            virtual void print() = 0;
    };
}

#endif
