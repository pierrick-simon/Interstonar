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
            Vector3D(const Vector3D &v1, const Vector3D &v2)
                : _x(v2._x - v1._x), _y(v2._y - v1._y), _z(v2._z - v1._z) {};

            double _x;
            double _y;
            double _z;

            void printVector();
            void printVector(std::size_t precision, std::string sep);
            void printVector(std::size_t precision, std::string sep,
                std::string local);
            
            double getNorm(Vector3D);
            double getNormalize() const;

            Vector3D operator*(const Vector3D &vec)
                {return {_x * vec._x, _y * vec._y, _z * vec._z};}
            Vector3D operator*(const double &coef)
                {return {_x * coef, _y * coef, _z * coef};}
            Vector3D operator/(const double &coef) const
                {return {_x / coef, _y / coef, _z / coef};}
            Vector3D operator-(const Vector3D &vec)
                {return {_x - vec._x, _y - vec._y, _z - vec._z};}
            Vector3D operator+(const Vector3D &vec)
                {return {_x + vec._x, _y + vec._y, _z + vec._z};}
            Vector3D &operator+=(const Vector3D &vec) {
                _x += vec._x;
                _y += vec._y;
                _z += vec._z;
                return *this;
            }
    };
}

#endif
