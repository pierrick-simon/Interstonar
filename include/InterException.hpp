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

    class ParseFileException : public ParsingException {
        public:
            ParseFileException(
                std::string str, std::string path, std::size_t line)
                : ParsingException("Parsing file: " + str + " At " + path
                    + ":" + std::to_string(line) + ".") {};
    };

    class ParseFileNotANumberException : public ParseFileException {
        public:
            ParseFileNotANumberException(std::string path, std::size_t line)
                : ParseFileException("Not a number.", path, line) {};
    };

    class ParseFileNotAVectorException : public ParseFileException {
        public:
            ParseFileNotAVectorException(std::string path, std::size_t line)
                : ParseFileException("Not a Vector3D.", path, line) {};
    };

    class ParseFileNotAStringException : public ParseFileException {
        public:
            ParseFileNotAStringException(std::string path, std::size_t line)
                : ParseFileException("Not a String.", path, line) {};
    };

    class ParseFileUnknowTypeException : public ParseFileException {
        public:
            ParseFileUnknowTypeException(std::string path, std::size_t line)
                : ParseFileException("Unknow Type.", path, line) {};
    };

    class ParseFileWrongArgsException : public ParseFileException {
        public:
            ParseFileWrongArgsException(std::string path, std::size_t line)
                : ParseFileException("Wrong Args.", path, line) {};
    };
}

#endif
