/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Main
*/

#include <iostream>
#include <deque>
#include "Interstonar.hpp"
#include "InterException.hpp"
#include "Parsing.hpp"

int main(int ac, char **av)
{
    std::queue<std::string> args(std::deque<std::string>(av + 1, av + ac));
    try {
        inter::Parsing parsing(args);
        if (parsing.isHelp())
            return SUCCESS;
        parsing.run();
    } catch (inter::InterException &e) {
        std::cout << e.what() << std::endl;
        return EPIERROR;
    }
    return SUCCESS;
}