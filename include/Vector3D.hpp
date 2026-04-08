/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

namespace inter {
    class Vector3D {
        public:
            Vector3D() : _x(0), _y(0), _z(0) {};
            Vector3D(double x, double y, double z)
                : _x(x), _y(y), _z(z) {};

            double _x;
            double _y;
            double _z;

            void printVector();
            void printVector(std::size_t precision, std::string sep);
            void printVector(std::size_t precision, std::string sep,
                std::string local);
    };
}

#endif
