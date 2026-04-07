/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Parsing
*/

#include <iostream>
#include <fstream>
#include "Parsing.hpp"
#include "InterException.hpp"
#include "Interstonar.hpp"

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

std::vector<inter::Astre> inter::Parsing::run()
{
    try {

    } catch (ParsingException &e) {
        throw e;
    }
    return _astres;
}