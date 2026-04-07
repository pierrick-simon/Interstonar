/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** InterException
*/

#ifndef INTEREXEPTION_HPP
    #define INTEREXEPTION_HPP

#include <exception>
#include <string>

namespace inter {
    class InterException : public std::exception {
        public:
            InterException(std::string str) : _str("Error: " + str) {};

            virtual const char *what() const noexcept override
                    { return _str.c_str(); };
        private:
            std::string _str;
    };

    class ParsingException : public InterException {
        ParsingException(std::string str)
            : InterException("Parsing: " + str) {}
    };
}

#endif
