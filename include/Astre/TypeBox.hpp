/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeBox
*/

#ifndef TYPEBOX_HPP
    #define TYPEBOX_HPP

#include "AType.hpp"

namespace inter {
    class TypeBox : public AType {
        public:
            TypeBox(Vector3D sides) : _sides(sides) {};
            ~TypeBox() {};

            bool isCollide(Vector3D vec) override {return false;}

        private:
            Vector3D _sides;
    };
}

#endif
