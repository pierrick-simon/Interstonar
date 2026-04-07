/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** IType
*/

#ifndef ITYPE_HPP
    #define ITYPE_HPP

#include "Vector3D.hpp"

namespace inter {

    enum class Type {
        Sphere,
        Cylinder,
        Box,
        Torus,
    };

    class AType {
        public:
            ~AType() = default;

            virtual bool isCollide(Vector3D) {return false;}
    };
}

#endif
