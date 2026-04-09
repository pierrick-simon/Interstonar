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

#include <memory>

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
    inter::Vector3D dir, double mass, std::unique_ptr<inter::IType> type)
{
    inter::Astre astre;

    astre.setName(name);
    astre.setPos(pos);
    astre.setVelocity(dir);
    astre.setMass(mass);
    astre.setType(std::move(type));
    return astre;
}

static const char *test_main(
    std::string file, bool ispath, inter::Mode mode, std::reference_wrapper<std::vector<inter::Astre>> astres)
{
    if (!ispath)
        file = "tests/testFiles/" + file;
    try {
        std::vector<inter::Astre> tmp;
        inter::ParseConfigFile parsing(file, mode, tmp);
        parsing.run();
        cr_assert_eq(tmp.size(), astres.get().size(), "Size");
        for (std::size_t i = 0; i < tmp.size() && i < astres.get().size(); i++) {
            cr_assert_str_eq(tmp[i].getName().c_str(), astres.get()[i].getName().c_str(), "Name");
            cr_assert_float_eq(tmp[i].getPos()._x, astres.get()[i].getPos()._x, 1e-6);
            cr_assert_float_eq(tmp[i].getPos()._y, astres.get()[i].getPos()._y, 1e-6,"Pos y");
            cr_assert_float_eq(tmp[i].getPos()._z, astres.get()[i].getPos()._z, 1e-6,"Pos z");
            cr_assert_float_eq(tmp[i].getVelocity()._x, astres.get()[i].getVelocity()._x, 1e-6,"Velocity x");
            cr_assert_float_eq(tmp[i].getVelocity()._y, astres.get()[i].getVelocity()._y, 1e-6,"Velocity y");
            cr_assert_float_eq(tmp[i].getVelocity()._z, astres.get()[i].getVelocity()._z, 1e-6,"Velocity z");
            cr_assert_float_eq(tmp[i].getMass(), astres.get()[i].getMass(), 1e-6, "Mass");
        };
    } catch (inter::InterException &e) {
        static std::string err;
        err = e.what();
        return err.c_str();
    }
    return "No Error";
}

Test(SubjectParsingFileTest, global_scene_example)
{
    std::vector<inter::Astre> astres;
    astres.push_back(initAstre("Sun",
        inter::Vector3D(1.81899E+8, 9.83630E+8, -1.58778E+8),
        inter::Vector3D(-1.12474E+1, 7.54876E+0, 2.68723E-1),
        1.98854e30,
        std::make_unique<inter::TypeSphere>(696342000)
    ));
    astres.push_back(initAstre("Mercury",
        inter::Vector3D(-5.67576E+10, -2.73592E+10, 2.89173E+9),
        inter::Vector3D(1.16497E+4, -4.14793E+4, -4.45952E+3),
        3.30200E+23,
        std::make_unique<inter::TypeSphere>(2439000)
    ));
    astres.push_back(initAstre("Venus",
        inter::Vector3D(4.28480E+10, 1.00073E+11, -1.11872E+09),
        inter::Vector3D(-3.22930E+04, 1.36960E+04, 2.05091E+03),
        4.86850E+24,
        std::make_unique<inter::TypeSphere>(6051000)
    ));
    cr_assert_str_eq(test_main("tests/example/global_scene_example.toml", true, inter::Mode::Global, astres), "No Error");
}

Test(SubjectParsingFileTest, infinite_cylinder)
{
    std::vector<inter::Astre> astres;
    astres.push_back(initAstre("CYLINDER_1",
        inter::Vector3D(0, 0, 12),
        inter::Vector3D(0, 0, 0),
        0,
        std::make_unique<inter::TypeCylinder>(1)
    ));
    cr_assert_str_eq(test_main("tests/example/infinite_cylinder.toml", true, inter::Mode::Local, astres), "No Error");
}

Test(SubjectParsingFileTest, local_scene_example)
{
    std::vector<inter::Astre> astres;
    astres.push_back(initAstre("s1",
        inter::Vector3D(0, 0, 0),
        inter::Vector3D(0, 0, 0),
        0,
        std::make_unique<inter::TypeSphere>(1)
    ));
    astres.push_back(initAstre("CYLINDER_1",
        inter::Vector3D(0, 0, 0),
        inter::Vector3D(0, 0, 0),
        0,
        std::make_unique<inter::TypeCylinder>(1, 100)
    ));
    astres.push_back(initAstre("BOX_1",
        inter::Vector3D(0, 0, 0),
        inter::Vector3D(0, 0, 0),
        0,
        std::make_unique<inter::TypeBox>(inter::Vector3D(10, 10, 10))
    ));
    astres.push_back(initAstre("t1",
        inter::Vector3D(0, 0, 0),
        inter::Vector3D(0, 0, 0),
        0,
        std::make_unique<inter::TypeTorus>(3, 1)
    ));
    cr_assert_str_eq(test_main("tests/example/local_scene_example.toml", true, inter::Mode::Local, astres), "No Error");
}

Test(ParsingFileTest, WrongExtension)
{
    std::vector<inter::Astre> astres;
    std::string file = "WrongExtension";
    std::string Error = "Error: Parsing: tests/testFiles/" + file + ": Wrong Extension.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Global, astres), Error.c_str());
}

Test(ParsingFileTest, WrongArgs)
{
    std::vector<inter::Astre> astres;
    std::string file = "WrongArgs.toml";
    std::string Error = "Error: Parsing: Parsing file: Wrong Args. At tests/testFiles/" + file + ":2.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Global, astres), Error.c_str());
}

Test(ParsingFileTest, NotAString)
{
    std::vector<inter::Astre> astres;
    std::string file = "NotAString.toml";
    std::string Error = "Error: Parsing: Parsing file: Not a String. At tests/testFiles/" + file + ":2.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Global, astres), Error.c_str());
}

Test(ParsingFileTest, NotAVector3D)
{
    std::vector<inter::Astre> astres;
    std::string file = "NotAVector3D.toml";
    std::string Error = "Error: Parsing: Parsing file: Not a Vector3D. At tests/testFiles/" + file + ":3.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Global, astres), Error.c_str());
}

Test(ParsingFileTest, NotANumber)
{
    std::vector<inter::Astre> astres;
    std::string file = "NotANumber.toml";
    std::string Error = "Error: Parsing: Parsing file: Not a Number. At tests/testFiles/" + file + ":5.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Global, astres), Error.c_str());
}

Test(ParsingFileTest, UnknowType)
{
    std::vector<inter::Astre> astres;
    std::string file = "UnknowType.toml";
    std::string Error = "Error: Parsing: Parsing file: Unknow Type. At tests/testFiles/" + file + ":3.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Local, astres), Error.c_str());
}

Test(ParsingFileTest, NotStartWritting)
{
    std::vector<inter::Astre> astres;
    std::string file = "NotStartWritting.toml";
    std::string Error = "Error: Parsing: Parsing file: Wrong Args. At tests/testFiles/" + file + ":1.";

    cr_assert_str_eq(test_main(file, false, inter::Mode::Global, astres), Error.c_str());
}