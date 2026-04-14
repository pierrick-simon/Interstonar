/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Interstonar
*/

#include <iostream>
#include <cmath>
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
        throw e;
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

void inter::Interstonar::computeAstre(Astre &astre)
{
    Vector3D f;
    if (astre != _rock)
        f += astre.getForce(_rock);
    for (const auto &iter: _astres)
        if (astre != iter)
            f += astre.getForce(iter);
    astre.applyForce(f, _time);
    if (astre == _rock)
        _rock_after = std::move(astre);
    else
        _astres_after.push_back(std::move(astre));
}


bool inter::Interstonar::computeGlobal()
{
    computeAstre(_rock);
    for (auto &astre: _astres)
        computeAstre(astre);
    _rock = std::move(_rock_after);
    _astres_after.swap(_astres);
    _astres_after.clear();
    return false;
}

void inter::Interstonar::runGlobal()
{
    std::cout << "Rock coordinates (x y z) are:" << std::endl;
    for (std::size_t i = 0; i <= NBSTEP; i++) {
        std::cout << "t = " << i << ": ";
        _rock.getPos().printVector(0, " ", "");
        std::cout << std::endl;
        computeGlobal();
    }
    std::cout << std::endl;
    std::cout << "Mission failure" << std::endl;
}

std::pair<double, std::string> inter::Interstonar::getShortestDist()
{
    std::pair<double, std::string> shortestDist;

    for (auto &astre: _astres) {
        auto dist = astre.getShortestDist(_rock.getPos());
        if (shortestDist.second.empty() || dist < shortestDist.first)
            shortestDist = {dist, astre.getName()};
    }
    return shortestDist;
}

bool inter::Interstonar::isEndLocal(
    std::pair<double, std::string> shortestDist)
{
    bool value = false;

    if (shortestDist.first <= 0.1) {
        std::cout << std::endl;
        std::cout << "Result: Intersection with " << shortestDist.second
            << std::endl;
        value = true;
    }
    if (shortestDist.first > OUTOFSCENE) {
        std::cout << std::endl;
        std::cout << "Result: Out of scene" << std::endl;
        value = true;
    }
    return value;
}

void inter::Interstonar::runLocal()
{
    printRock();
    for (auto &astre: _astres)
        astre.print();
    std::cout << std::endl;
    for (std::size_t i = 1; i <= NBSTEP; i++) {
        auto shortestDist = getShortestDist();
        _rock.move(shortestDist.first);
        std::cout << "Step " << i << ": ";
        _rock.getPos().printVector(2, ", ");
        std::cout << std::endl;
        if (isEndLocal(shortestDist))
            return;
    }
    std::cout << std::endl;
    std::cout << "Result: Steps limit reached" << std::endl;
}
