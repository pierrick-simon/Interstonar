/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <functional>

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
            
            double getNorm(Vector3D);
            double getNormalize();

            Vector3D operator*(Vector3D vec)
                {return {_x * vec._x, _y * vec._y, _z * vec._z};}
            Vector3D operator-(Vector3D vec)
                {return {_x - vec._x, _y - vec._y, _z - vec._z};}
    };
}

#endif
