/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Parsing
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Parsing.hpp"
#include "InterException.hpp"
#include "Interstonar.hpp"
#include "TypeSphere.hpp"
#include "ParseConfigFile.hpp"

void inter::Parsing::showHelp()
{
    std::ifstream file({std::string(HELP)});

    if (file.is_open())
        std::cout << file.rdbuf();
}

bool inter::Parsing::isHelp()
{
    bool value = false;

    if (!_args.empty() && std::string(HELPFLAG) == _args.front()) {
        showHelp();
        value = true;
    }
    return value;
}

void inter::Parsing::parseMode()
{
    if (_args.empty())
        throw WrongArgsException();
    for (auto mode: _availableMode) {
        if (mode.first == _args.front()) {
            _mode = mode.second;
            _args.pop();
            return;
        }
    }
    throw WrongArgsException();
}

void inter::Parsing::parseFile()
{
    if (_args.empty())
        throw WrongArgsException();
    std::ifstream file(_args.front());

    try {
        ParseConfigFile parse(_args.front(), _mode, _astres);
        parse.run();
    } catch (ParsingException &e) {
        throw e;
    }
    _args.pop();
}

void inter::Parsing::parseTime()
{
    if (_args.empty())
        throw WrongArgsException();
    try {
        if (_args.front() == SIMPLEDELTAFLAG) {
            _args.pop();
            _time = getSizeT(_args.front());
        } else if (_args.front().starts_with(DELTAFLAG)) {
            auto tmp = _args.front().substr(DELTAFLAG.size());
            _time = getSizeT(tmp);
        } else 
            throw WrongArgsException();
    } catch (ParsingException &e) {
        throw e;
    }
    _args.pop();
}

void inter::Parsing::parserock()
{
    _rock.get().setName("rock");
    _rock.get().setMass(DEFAULTMASS);
    _rock.get().setType(std::make_unique<TypeSphere>(DEFAULTRADIUS));
    try {
        _rock.get().setPos({
            parseDouble(),
            parseDouble(),
            parseDouble()
        });
        _rock.get().setVelocity({
            parseDouble(),
            parseDouble(),
            parseDouble()
        });
    } catch (ParsingException &e) {
        throw e;
    }
}

double inter::Parsing::parseDouble()
{
    if (_args.empty())
        throw WrongArgsException();
    std::istringstream tmp(_args.front());
    double nb;
    tmp >> nb;
    if (tmp.fail())
        throw NotANumberException(_args.front());
    _args.pop();
    return nb;
}

std::size_t inter::Parsing::getSizeT(std::string str)
{
    std::istringstream tmp(str);
    std::size_t nb;
    tmp >> nb;
    if (tmp.fail())
        throw NotANumberException(str);
    return nb;
}

void inter::Parsing::run()
{
    try {
        parseMode();
        parseFile();
        if (_mode == Mode::Global)
            parseTime();
        parserock();
        if (!_args.empty())
            throw WrongArgsException();
    } catch (ParsingException &e) {
        throw e;
    }
}

const std::unordered_map<std::string, inter::Mode>
    inter::Parsing::_availableMode = {
    {"--global", Mode::Global},
    {"--local", Mode::Local},
};