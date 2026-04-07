/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** Parsing
*/

#ifndef PARSINNG_HPP
    #define PARSINNG_HPP

#include <string_view>
#include <vector>
#include <utility>
#include <optional>
#include "Astre.hpp"

namespace inter {

    constexpr std::string_view HELP = "public/help.txt";
    constexpr std::string_view HELPFLAG = "--help";

    enum class Mode {
        GLobal,
        Local,        
    };

    class Parsing {
        public:
            Parsing(std::vector<std::string> args) : _args(args) {};
            ~Parsing() {};

            std::vector<Astre> run();
            void showHelp();
            bool isHelp();

            Mode getMod() {return _mode;}
            

        private:
            std::vector<std::string> _args;
            std::vector<Astre> _astres;
            Mode _mode;
    };
}

#endif
