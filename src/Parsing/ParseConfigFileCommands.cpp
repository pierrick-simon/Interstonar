/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** ParsingConfigFileCommands
*/

#include <algorithm>
#include "ParseConfigFile.hpp"
#include "InterException.hpp"
#include "TypeSphere.hpp"

void inter::ParseConfigFile::name(
    std::string line, std::reference_wrapper<Astre> astre)
{
    try {
        astre.get().setName(parseString(line));
        for (auto &tmp: _astres.get()) {
            if (tmp.getName() == astre.get().getName())
                throw ParseFileSameName(_filePath, _line);
        }
    } catch (ParseFileException &e) {
        throw e;
    }
}

void inter::ParseConfigFile::position(
    std::string line, std::reference_wrapper<Astre> astre)
{
    try {
        astre.get().setPos(parseVec(line));
    } catch (ParseFileException &e) {
        throw e;
    }
}

void inter::ParseConfigFile::direction(
    std::string line, std::reference_wrapper<Astre> astre)
{
    try {
        astre.get().setVelocity(parseVec(line));
    } catch (ParseFileException &e) {
        throw e;
    }
}

void inter::ParseConfigFile::mass(
    std::string line, std::reference_wrapper<Astre> astre)
{
    try {
        astre.get().setMass(parseDouble(line));
    } catch (ParseFileException &e) {
        throw e;
    }
}

void inter::ParseConfigFile::radius(
    std::string line, std::reference_wrapper<Astre> astre)
{
    try {
        TypeSphere sphere(parseDouble(line));
        astre.get().setType(std::make_unique<TypeSphere>(sphere));
    } catch (ParseFileException &e) {
        throw e;
    }
}

void inter::ParseConfigFile::type(
    std::string line, std::reference_wrapper<Astre> astre)
{
    try {
        auto type = parseString(line);
        auto func = _types.find(type);
        if (func == _types.end())
            throw ParseFileUnknowTypeException(_filePath, _line);
        astre.get().setType(func->second());
        _astreTypes.push_back(type);
        if (astre.get().getName().empty()) {
            auto count = std::count(_astreTypes.begin(), _astreTypes.end(), type);
            std::transform(type.begin(), type.end(), type.begin(), ::toupper);
            astre.get().setName(type + "_" + std::to_string(count));
        }
    } catch (ParseFileException &e) {
        throw e;
    }
}

const inter::Order inter::ParseConfigFile::_globalCommands = {
    {"name", true},
    {"position", true},
    {"direction", true},
    {"mass", true},
    {"radius", true},
};

const inter::Order inter::ParseConfigFile::_localCommands = {
    {"name", false},
    {"position", true},
    {"type", true},
};
