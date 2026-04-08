/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** TypeBox
*/

#ifndef TYPEBOX_HPP
    #define TYPEBOX_HPP

#include "IType.hpp"

namespace inter {
    class TypeBox : public IType {
        public:
            TypeBox(Vector3D sides) : _sides(sides) {};
            ~TypeBox() {};

            bool isCollide(Vector3D vec) override {return false;}
            void print() override;

        private:
            Vector3D _sides;
    };
}

#endif
