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
#include "AType.hpp"

namespace inter {
    class Astre {
        public:
            Astre(std::string name) : _name(name) {};
            ~Astre() {};

            void setPos(Vector3D pos) {_pos = pos;}
            void setVelocity(Vector3D velocity) {_velocity = velocity;}
            void setMass(double mass) {_mass = mass;}
            void setType(AType type) {_type = type;}

            Vector3D getPos() {return _pos;}
            Vector3D getVelocity() {return _velocity;}
            double getMass() {return _mass;}
            AType getType() {return _type;}

        private:
            std::string _name;
            Vector3D _pos;
            Vector3D _velocity;
            double _mass;
            AType _type;
    };
}

#endif
