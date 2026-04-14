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

    constexpr double G = 6.674E-11;

    class Astre {
        public:
            Astre() {};
            ~Astre() {};

            Astre(Astre&&) noexcept = default;
            Astre& operator=(Astre&&) noexcept = default;

            Astre(const Astre&) = delete;
            Astre& operator=(const Astre&) = delete;
            bool operator==(const Astre& astre) { return &astre == this; };
            bool operator!=(const Astre& astre) { return &astre != this; };

            std::unique_ptr<IType> &operator->() { return _type; };

            void setPos(Vector3D pos) {_pos = pos;}
            void setVelocity(Vector3D velocity) {_velocity = velocity;}
            void setMass(double mass) {_mass = mass;}
            void setType(std::unique_ptr<IType> type) {_type = std::move(type);}
            void setName(std::string name) {_name = name;}

            Vector3D getPos() const {return _pos;}
            Vector3D getVelocity() const {return _velocity;}
            double getMass() const {return _mass;}
            std::string getName() const {return _name;}
            double getShortestDist(Vector3D point) const
                {return _type->sdfFunc(point, _pos);}

            void print();
            void reset();
            void move(double dist);

            Vector3D getForce(const Astre &astre) const;
            void applyForce(const Vector3D &force, const std::size_t &dt);

        private:
            std::string _name;
            Vector3D _pos;
            Vector3D _velocity;
            double _mass;
            std::unique_ptr<IType> _type;
    };
}

#endif
