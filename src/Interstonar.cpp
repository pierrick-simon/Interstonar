/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Interstonar
*/

#include <iostream>
#include "Interstonar.hpp"
#include "InterException.hpp"
#include "Parsing.hpp"

inter::Interstonar::Interstonar(std::queue<std::string> args)
{
    try {
        Parsing parsing(args, _astres, _rock);
        parsing.run();
        _time = parsing.getTime();
        _mode = parsing.getMod();
    } catch (inter::InterException &e) {
        throw &e;
    }
    _runs[Mode::Global] = [this]() {runGlobal();};
    _runs[Mode::Local] = [this]() {runLocal();};
}

void inter::Interstonar::printRock()
{
    std::cout << "Rock thrown at the point ";
    _rock.getPos().printVector(2, ", ");
    std::cout << " and parallel to the vector ";
    _rock.getVelocity().printVector(2, ", ");
    std::cout << std::endl;
}

void inter::Interstonar::run()
{
    auto command = _runs.find(_mode);
    
    if (command != _runs.end())
        command->second();
}

void inter::Interstonar::runGlobal()
{
    std::cout << "Rock coordinates (x y z) are:" << std::endl;
    for (std::size_t i = 1; i <= NBSTEP; i++) {
        std::cout << "t = " << i << ": ";
        _rock.getPos().printVector(0, " ", "");
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Mission failure" << std::endl;
}

void inter::Interstonar::runLocal()
{
    printRock();
    for (auto &astre: _astres)
        astre.print();
    std::cout << std::endl;
    for (std::size_t i = 1; i <= NBSTEP; i++) {
        std::cout << "Step " << i << ": ";
        _rock.getPos().printVector(2, ", ");
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Result: Steps limit reached" << std::endl;
}
