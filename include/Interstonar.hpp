/*
** EPITECH PROJECT, 2026
** Intersonar
** File description:
** Interstonar
*/

#ifndef INTERSTONAR_HPP
    #define INTERSTONAR_HPP

constexpr int SUCCESS = 0;
constexpr int EPIERROR = 84;
constexpr int SKIP = -1;

#include <vector>
#include <unordered_map>
#include <functional>
#include <queue>
#include "Astre.hpp"

namespace inter {

    constexpr std::size_t NBSTEP = 1000;

    enum class Mode {
        Global,
        Local,        
    };

    class Interstonar {
        public:
            Interstonar(std::queue<std::string> args);
            ~Interstonar() {};
        
            void run();

            void runGlobal();
            void runLocal();

            void printRock();

        private:
            std::vector<Astre> _astres;
            Astre _rock;
            Mode _mode;
            std::size_t _time;
            std::unordered_map<Mode, std::function<void()>> _runs;
    };
}

#endif
