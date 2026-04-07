/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** ParseConfigFile
*/

#ifndef PARSECONFIGFILE_HPP
    #define PARSECONFIGFILE_HPP

#include <fstream>
#include <optional>
#include <functional>
#include "Parsing.hpp"

namespace inter {

    constexpr std::string_view SPHEREARGONE = "radius";
    constexpr std::string_view CYLINDERARGONE = "radius";
    constexpr std::string_view CYLINDERARGTWO = "height";
    constexpr std::string_view BOXARGONE = "sides";
    constexpr std::string_view TORUSARGONE = "inner_radius";
    constexpr std::string_view TORUSARGTWO = "outer_radius";

    using Command = std::function<
        void(std::string line, std::reference_wrapper<Astre> astre)>;
    using Commands = std::unordered_map<std::string, Command>;
    using Order = std::vector<std::pair<std::string, bool>>;

    class ParseConfigFile {
        public:
            ParseConfigFile(std::string file, Mode mode);
            ~ParseConfigFile() {};

            std::vector<Astre> run();

        private:
            static const Order _globalCommands;
            static const Order _localCommands;
            std::unordered_map<std::string, std::function<AType()>> _types;
            Commands _commands;
            std::string _filePath;
            std::ifstream _file;
            Mode _mode;
            std::size_t _line = 0;
            std::vector<Astre> _astres;

            void removeComment(
                std::reference_wrapper<std::string> str);
            bool customGetline(std::reference_wrapper<std::string> str);
            std::optional<Command> getCommand(
                Order::iterator iter, Order order, std::string line);
            void checkCommand(Order order, std::string line);
            double getDouble(std::string str);
            Vector3D parseVec(std::string line);
            double parseDouble(std::string line);
            std::string parseString(std::string line);


            void name(std::string line, std::reference_wrapper<Astre> astre);
            void position(std::string line, std::reference_wrapper<Astre> astre);
            void direction(std::string line, std::reference_wrapper<Astre> astre);
            void mass(std::string line, std::reference_wrapper<Astre> astre);
            void radius(std::string line, std::reference_wrapper<Astre> astre);
            void type(std::string line, std::reference_wrapper<Astre> astre);

            AType shpere();
            AType cylinder();
            AType box();
            AType torus();
    };
}

#endif
