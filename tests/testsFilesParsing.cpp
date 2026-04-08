/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** testsFilesParsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>

#include "InterException.hpp"
#include "ParseConfigFile.hpp"

#include "TypeSphere.hpp"
#include "TypeCylinder.hpp"
#include "TypeBox.hpp"
#include "TypeTorus.hpp"

#include <iostream>
#define DEBUG(value) std::cout << "\e[0;35m" << "DEBUG: " <<  "\e[0;37m" << "\t" << value << std::endl;

static void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static inter::Astre initAstre(std::string name, inter::Vector3D pos,
    inter::Vector3D dir, double mass, inter::AType type)
{
    inter::Astre astre;

    astre.setName(name);
    astre.setPos(pos);
    astre.setVelocity(dir);
    astre.setMass(mass);
    astre.setType(type);
    return astre;
}

static const char *test_main(std::string file, bool ispath, inter::Mode mode, std::vector<inter::Astre> astres)
{
    if (!ispath)
        file = "tests/testFiles/" + file;
    try {
        inter::ParseConfigFile parsing(file, mode);
        auto tmp = parsing.run();
        cr_assert_eq(tmp.size(), astres.size(), "Size");
        for (std::size_t i = 0; i < tmp.size() || i < astres.size(); i++) {
            cr_assert_str_eq(tmp[i].getName().c_str(), astres[i].getName().c_str(), "Name");
            cr_assert_float_eq(tmp[i].getPos()._x, astres[i].getPos()._x, 1e-6);
            cr_assert_float_eq(tmp[i].getPos()._y, astres[i].getPos()._y, 1e-6,"Pos y");
            cr_assert_float_eq(tmp[i].getPos()._z, astres[i].getPos()._z, 1e-6,"Pos z");
            cr_assert_float_eq(tmp[i].getVelocity()._x, astres[i].getVelocity()._x, 1e-6,"Velocity x");
            cr_assert_float_eq(tmp[i].getVelocity()._y, astres[i].getVelocity()._y, 1e-6,"Velocity y");
            cr_assert_float_eq(tmp[i].getVelocity()._z, astres[i].getVelocity()._z, 1e-6,"Velocity z");
            cr_assert_float_eq(tmp[i].getMass(), astres[i].getMass(), 1e-6, "Mass");
        };
    } catch (inter::InterException &e) {
        std::string *tmp = new std::string(e.what());
        return tmp->c_str();
    }
    return "No Error";
}

Test(SubjectParsingFileTest, global_scene_example)
{
    std::vector<inter::Astre> astres = {
        initAstre("Sun",
            inter::Vector3D(1.81899E+8, 9.83630E+8, -1.58778E+8),
            inter::Vector3D(-1.12474E+1, 7.54876E+0, 2.68723E-1),
            1.98854e30,
            inter::TypeSphere(696342000)
        ),
        initAstre("Mercury",
            inter::Vector3D(-5.67576E+10, -2.73592E+10, 2.89173E+9),
            inter::Vector3D(1.16497E+4, -4.14793E+4, -4.45952E+3),
            3.30200E+23,
            inter::TypeSphere(2439000)
        ),
        initAstre("Venus",
            inter::Vector3D(4.28480E+10, 1.00073E+11, -1.11872E+09),
            inter::Vector3D(-3.22930E+04, 1.36960E+04, 2.05091E+03),
            4.86850E+24,
            inter::TypeSphere(6051000)
        ),
    }; 
    cr_assert_str_eq(test_main("tests/example/global_scene_example.toml", true, inter::Mode::GLobal, astres), "No Error");
}

Test(SubjectParsingFileTest, infinite_cylinder)
{
    std::vector<inter::Astre> astres = {
        initAstre("",
            inter::Vector3D(0, 0, 12),
            inter::Vector3D(0, 0, 0),
            0,
            inter::TypeCylinder(1)
        ),
    }; 
    cr_assert_str_eq(test_main("tests/example/infinite_cylinder.toml", true, inter::Mode::Local, astres), "No Error");
}

Test(SubjectParsingFileTest, local_scene_example)
{
    std::vector<inter::Astre> astres = {
        initAstre("s1",
            inter::Vector3D(0, 0, 0),
            inter::Vector3D(0, 0, 0),
            0,
            inter::TypeSphere(1)
        ),
        initAstre("",
            inter::Vector3D(0, 0, 0),
            inter::Vector3D(0, 0, 0),
            0,
            inter::TypeCylinder(1, 100)
        ),
        initAstre("",
            inter::Vector3D(0, 0, 0),
            inter::Vector3D(0, 0, 0),
            0,
            inter::TypeBox(inter::Vector3D(10, 10, 10))
        ),
        initAstre("t1",
            inter::Vector3D(0, 0, 0),
            inter::Vector3D(0, 0, 0),
            0,
            inter::TypeTorus(3, 1)
        ),
    }; 
    cr_assert_str_eq(test_main("tests/example/local_scene_example.toml", true, inter::Mode::Local, astres), "No Error");
}

Test(ParsingFileTest, WrongExtension)
{
    std::string file = "WrongExtension";
    std::string Error = "Error: Parsing: tests/testFiles/" + file + ": Wrong Extension.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::GLobal, {}), Error.c_str());
}

Test(ParsingFileTest, WrongArgs)
{
    std::string file = "WrongArgs.toml";
    std::string Error = "Error: Parsing: Parsing file: Wrong Args. At tests/testFiles/" + file + ":2.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::GLobal, {}), Error.c_str());
}

Test(ParsingFileTest, NotAString)
{
    std::string file = "NotAString.toml";
    std::string Error = "Error: Parsing: Parsing file: Not a String. At tests/testFiles/" + file + ":2.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::GLobal, {}), Error.c_str());
}

Test(ParsingFileTest, NotAVector3D)
{
    std::string file = "NotAVector3D.toml";
    std::string Error = "Error: Parsing: Parsing file: Not a Vector3D. At tests/testFiles/" + file + ":3.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::GLobal, {}), Error.c_str());
}

Test(ParsingFileTest, NotANumber)
{
    std::string file = "NotANumber.toml";
    std::string Error = "Error: Parsing: Parsing file: Not a Number. At tests/testFiles/" + file + ":5.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::GLobal, {}), Error.c_str());
}

Test(ParsingFileTest, UnknowType)
{
    std::string file = "UnknowType.toml";
    std::string Error = "Error: Parsing: Parsing file: Unknow Type. At tests/testFiles/" + file + ":3.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Local, {}), Error.c_str());
}

Test(ParsingFileTest, NotStartWritting)
{
    std::string file = "NotStartWritting.toml";
    std::string Error = "Error: Parsing: Parsing file: Wrong Args. At tests/testFiles/" + file + ":1.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::GLobal, {}), Error.c_str());
}
