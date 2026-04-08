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
#include <queue>
#include <utility>
#include <optional>
#include <unordered_map>
#include "Astre.hpp"
#include "Interstonar.hpp"

namespace inter {

    constexpr std::string_view HELP = "public/help.txt";
    constexpr std::string_view HELPFLAG = "--help";

    constexpr std::string_view SIMPLEDELTAFLAG  = "-d";
    constexpr std::string_view DELTAFLAG  = "--delta=";

    constexpr double DEFAULTMASS = 1000;
    constexpr double DEFAULTRADIUS = 1;
    constexpr std::string_view DEFAULTNAME = "rock";

    class Parsing {
        public:
            Parsing(std::queue<std::string> args,
                std::reference_wrapper<std::vector<Astre>> astres,
                std::reference_wrapper<Astre> rock)
                : _args(args), _astres(astres), _rock(rock) {};
            ~Parsing() {};

            void run();
            void showHelp();
            bool isHelp();

            Mode getMod() {return _mode;}
            std::size_t getTime() {return _time;}

        private:
            static const std::unordered_map<std::string, Mode> _availableMode;
            std::queue<std::string> _args;
            std::reference_wrapper<std::vector<Astre>> _astres;
            std::reference_wrapper<Astre> _rock;
            Mode _mode;
            std::size_t _time;

            void parseMode();
            void parseFile();
            void parseTime();
            void parserock();
            double parseDouble();
            std::size_t getSizeT(std::string);
    };
}

#endif
