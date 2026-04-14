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

            double getBounds() const override { return _sides.getNormalize(); };
            double sdfFunc(Vector3D point, Vector3D pos) override;
            void print() override;

        private:
            Vector3D _sides;
    };
}

#endif
