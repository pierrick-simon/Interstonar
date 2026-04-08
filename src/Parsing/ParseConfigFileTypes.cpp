/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** ParsingConfigFileType
*/

#include "ParseConfigFile.hpp"
#include "InterException.hpp"
#include "TypeSphere.hpp"
#include "TypeCylinder.hpp"
#include "TypeBox.hpp"
#include "TypeTorus.hpp"

std::unique_ptr<inter::IType> inter::ParseConfigFile::shpere()
{
    try {
        std::string line;
        if (!customGetline(line) || !line.starts_with(SPHEREARGONE))
            throw ParseFileWrongArgsException(_filePath, _line);
        TypeSphere sphere(parseDouble(line));
        return std::make_unique<TypeSphere>(sphere);
    } catch (ParseFileException &e) {
        throw e;
    }
}

std::unique_ptr<inter::IType> inter::ParseConfigFile::cylinder()
{
    try {
        std::string line;
        TypeCylinder cylinder(0);
        if (!customGetline(line) || !line.starts_with(CYLINDERARGONE))
            throw ParseFileWrongArgsException(_filePath, _line);
        float radius = parseDouble(line);
        if (!customGetline(line))
            cylinder = TypeCylinder(radius);
        else if (line.starts_with(CYLINDERARGTWO))
            cylinder = TypeCylinder(radius, parseDouble(line));
        else
            throw ParseFileWrongArgsException(_filePath, _line);
        return std::make_unique<TypeCylinder>(cylinder);
    } catch (ParseFileException &e) {
        throw e;
    }
}

std::unique_ptr<inter::IType> inter::ParseConfigFile::box()
{
    try {
        std::string line;
        if (!customGetline(line) || !line.starts_with(BOXARGONE))
            throw ParseFileWrongArgsException(_filePath, _line);
        TypeBox box(parseVec(line));
        return std::make_unique<TypeBox>(box);
    } catch (ParseFileException &e) {
        throw e;
    }
}

std::unique_ptr<inter::IType> inter::ParseConfigFile::torus()
{
    try {
        std::string line;
        if (!customGetline(line) || !line.starts_with(TORUSARGONE))
            throw ParseFileWrongArgsException(_filePath, _line);
        float innerRadius = parseDouble(line);
        if (!customGetline(line) || !line.starts_with(TORUSARGTWO))
            throw ParseFileWrongArgsException(_filePath, _line);
        TypeTorus torus(innerRadius, parseDouble(line));
        return std::make_unique<TypeTorus>(torus);
    } catch (ParseFileException &e) {
        throw e;
    }
}
