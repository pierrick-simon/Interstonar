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
        public:
            ParsingException(std::string str)
                : InterException("Parsing: " + str) {}
    };

    class WrongArgsException : public ParsingException {
        public:
            WrongArgsException()
                : ParsingException("Wrongs Args. Use ./interstonar --help") {};
    };

    class NoSuchFileException : public ParsingException {
        public:
            NoSuchFileException(std::string str)
                : ParsingException(str + ": No Such File.") {};
    };

    class NotANumberException : public ParsingException {
        public:
            NotANumberException(std::string str)
                : ParsingException(str + ": Not a number.") {};
    };
}

#endif
