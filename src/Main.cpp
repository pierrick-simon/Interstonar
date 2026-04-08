/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Main
*/

#include <iostream>
#include "Interstonar.hpp"
#include "InterException.hpp"
#include "Parsing.hpp"

int main(int ac, char **av)
{
    std::queue<std::string> args(std::deque<std::string>(av + 1, av + ac));
    try {
        inter::Interstonar interstonar(args);
        interstonar.run();
    } catch (inter::InterException &e) {
        std::cout << e.what() << std::endl;
        return EPIERROR;
    }
    return SUCCESS;
}