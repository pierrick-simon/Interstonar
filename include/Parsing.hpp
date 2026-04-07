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

namespace inter {

    constexpr std::string_view HELP = "public/help.txt";
    constexpr std::string_view HELPFLAG = "--help";

    constexpr std::string_view SIMPLEDELTAFLAG  = "-h";
    constexpr std::string_view DELTAFLAG  = "--delta=";

    constexpr double DEFAULTMASS = 1000;
    constexpr double DEFAULTRADIUS = 100;
    constexpr std::string_view DEFAULTNAME = "Stone";
    
    enum class Mode {
        GLobal,
        Local,        
    };

    class Parsing {
        public:
            Parsing(std::queue<std::string> args) : _args(args) {};
            ~Parsing() {};

            void run();
            void showHelp();
            bool isHelp();

            Mode getMod() {return _mode;}
            std::size_t getTime() {return _time;}
            std::vector<Astre> getAstres() {return _astres;}
            Astre getStone() {return _stone;}

        private:
            static const std::unordered_map<std::string, Mode> _availableMode;
            std::queue<std::string> _args;
            std::vector<Astre> _astres;
            Astre _stone;
            Mode _mode;
            std::size_t _time;

            void parseMode();
            void parseFile();
            void parseTime();
            void parseStone();
            double parseDouble();
            std::size_t getSizeT(std::string);
    };
}

#endif
