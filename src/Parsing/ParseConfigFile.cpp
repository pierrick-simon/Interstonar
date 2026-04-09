/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** ParseConfigFile
*/

#include <regex>
#include <fstream>
#include "ParseConfigFile.hpp"
#include "InterException.hpp"

inter::ParseConfigFile::ParseConfigFile(std::string file, Mode mode,
    std::reference_wrapper<std::vector<Astre>> astres)
    : _filePath(file), _file(file), _mode(mode), _astres(astres)
{
    if (!file.ends_with(".toml"))
        throw WrongExtensionException(file);
    if (!_file.is_open())
        throw NoSuchFileException(file);

    _types["sphere"] = [this]() -> std::unique_ptr<IType> {return shpere();};
    _types["cylinder"] = [this]() -> std::unique_ptr<IType> {return cylinder();};
    _types["box"] = [this]() -> std::unique_ptr<IType> {return box();};
    _types["torus"] = [this]() -> std::unique_ptr<IType> {return torus();};

    _commands["name"] = [this](std::string line,
        std::reference_wrapper<Astre> astre) {name(line, astre);};
    _commands["position"] = [this](std::string line,
        std::reference_wrapper<Astre> astre) {position(line, astre);};
    _commands["direction"] = [this](std::string line,
        std::reference_wrapper<Astre> astre) {direction(line, astre);};
    _commands["mass"] = [this](std::string line,
        std::reference_wrapper<Astre> astre) {mass(line, astre);};
    _commands["radius"] = [this](std::string line,
        std::reference_wrapper<Astre> astre) {radius(line, astre);};
    _commands["type"] = [this](std::string line,
        std::reference_wrapper<Astre> astre) {type(line, astre);};
}

void inter::ParseConfigFile::removeComment(
    std::reference_wrapper<std::string> str)
{
    size_t pos = str.get().find("#");
    if (pos != std::string::npos)
        str.get().replace(pos, str.get().length() - pos, "\0");
}

bool inter::ParseConfigFile::customGetline(
    std::reference_wrapper<std::string> str)
{
    bool value = false;
    if (std::getline(_file, str.get())) {
        _line++;
        value = true;
        removeComment(str);
        if (str.get().empty())
            value = customGetline(str);
    }
    return value;
}

double inter::ParseConfigFile::getDouble(std::string str)
{
    std::istringstream tmp(str);
    double nb;
    tmp >> nb;
    if (tmp.fail())
        throw ParseFileNotANumberException(_filePath, _line);
    return nb;
}

inter::Vector3D inter::ParseConfigFile::parseVec(std::string line)
{
    std::regex re(R"(\{x = ([^,]+), y = ([^,]+), z = ([^\}]+)\})");
    std::smatch m;
    std::regex_search(line, m, re);

    if (m.size() != 4)
        throw ParseFileNotAVectorException(_filePath, _line);
    try {
        return Vector3D(getDouble(m[1]), getDouble(m[2]), getDouble(m[3]));
    } catch (ParseFileException &e) {
        throw e;
    }
}

double inter::ParseConfigFile::parseDouble(std::string line)
{
    std::string val = line.substr(line.find('=') + 1);
    val.erase(std::remove(val.begin(), val.end(), '_'), val.end());

    try {
        return getDouble(val);
    } catch (ParseFileException &e) {
        throw e;
    }
}

std::string inter::ParseConfigFile::parseString(std::string line)
{
    size_t start = line.find('"');
    size_t end = line.rfind('"');

    if (start == std::string::npos || start == end)
        throw ParseFileNotAStringException(_filePath, _line);
    start++;
    return line.substr(start, end - start);
}

std::optional<inter::Command> inter::ParseConfigFile::getCommand(
    Order::iterator iter, Order order, std::string line)
{
    std::optional<inter::Command> value;
    bool next = false;

    if (iter == order.end())
        throw ParseFileWrongArgsException(_filePath, _line);
    if (!line.starts_with(iter->first)) {
        if (iter->second)
            throw ParseFileWrongArgsException(_filePath, _line);
        else
            next = true;
    }
    if (!next) {
        auto command = _commands.find(iter->first);
        if (command == _commands.end())
            throw ParseFileWrongArgsException(_filePath, _line);
        value = command->second;
    }
    return value;
}

bool inter::ParseConfigFile::startWriting(std::reference_wrapper<Astre> astre,
    std::reference_wrapper<bool> writing, std::string line)
{
    bool value = false;

    if (!writing.get()) {
        if (line.starts_with("[[body]]")) {
            astre.get().reset();
            writing.get() = true;
            value = true;
        } else
            throw ParseFileWrongArgsException(_filePath, _line);
    }
    return value;
}

void inter::ParseConfigFile::checkCommand(Order order, std::string line)
{
    static auto iter = order.begin();
    static bool writing = false;
    static Astre astre;
    bool skip = false;

    try {
        if (startWriting(astre, writing, line))
            return;
        auto command = getCommand(iter, order, line);
        iter++;
        if (command.has_value())
            command.value()(line, astre);
        else {
            checkCommand(order, line);
            skip = true;
        }
        if (!skip && iter == order.end()) {
            _astres.get().push_back(std::move(astre));
            writing = false;
            iter = order.begin();
        }
    } catch (ParseFileException &e) {
        throw e;
    }
    
}

void inter::ParseConfigFile::run()
{
    auto order = _globalCommands;
    if (_mode == Mode::Local)
        order = _localCommands;
    std::string line;
    try {
        while (customGetline(line))
            checkCommand(order, line);
    } catch (ParseFileException &e) {
        throw e;
    }
}
