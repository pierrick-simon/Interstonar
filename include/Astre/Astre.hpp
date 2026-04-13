/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Astre
*/

#ifndef ASTRE_HPP
    #define ASTRE_HPP

#include <string>
#include <memory>
#include "Vector3D.hpp"
#include "IType.hpp"

namespace inter {
    class Astre {
        public:
            Astre() {};
            ~Astre() {};

            Astre(Astre&&) noexcept = default;
            Astre& operator=(Astre&&) noexcept = default;

            Astre(const Astre&) = delete;
            Astre& operator=(const Astre&) = delete;

            void setPos(Vector3D pos) {_pos = pos;}
            void setVelocity(Vector3D velocity) {_velocity = velocity;}
            void setMass(double mass) {_mass = mass;}
            void setType(std::unique_ptr<IType> type) {_type = std::move(type);}
            void setName(std::string name) {_name = name;}

            Vector3D getPos() {return _pos;}
            Vector3D getVelocity() {return _velocity;}
            double getMass() {return _mass;}
            std::string getName() {return _name;}
            double getShortestDist(Vector3D point)
                {return _type->sdfFunc(point, _pos);}

            void print();
            void reset();
            void move(double dist);

        private:
            std::string _name;
            Vector3D _pos;
            Vector3D _velocity;
            double _mass;
            std::unique_ptr<IType> _type;
    };
}

#endif
