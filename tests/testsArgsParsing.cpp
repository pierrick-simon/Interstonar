/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** tests_parsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>

#include <queue>

#include "Interstonar.hpp"
#include "InterException.hpp"
#include "Parsing.hpp"

static void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static const char *test_main(std::queue<std::string> args)
{
    try {
        inter::Parsing parsing(args);
        if (parsing.isHelp())
            return "HELP";
        parsing.run();
    } catch (inter::InterException &e) {
        std::string *tmp = new std::string(e.what());
        return tmp->c_str();
    }
    return "No Error";
}

Test(SubjectParsingTest, global_scene_example)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--global",
    "tests/example/global_scene_example.toml",
    "--delta=360",
    "1", "2", "3", "4", "5", "6",
    });
    cr_assert_str_eq(test_main(args), "No Error");
}

Test(SubjectParsingTest, infinite_cylinder)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--local",
    "tests/example/infinite_cylinder.toml",
    "3", "-6.2", "12", "0", "0", "10.3",
    });
    cr_assert_str_eq(test_main(args), "No Error");
}

Test(SubjectParsingTest, local_scene_example)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--local",
    "tests/example/local_scene_example.toml",
    "10", "0", "35", "-1", "0", "-2",
    });
    cr_assert_str_eq(test_main(args), "No Error");
}

Test(ParsingTest, ParsingHelp, .init = redirect_all_std)
{
   std::queue<std::string> args(std::deque<std::string>{
    "--help"
    });
    cr_assert_str_eq(test_main(args), "HELP"); 
}

Test(ParsingTest, WrongMode)
{
    std::queue<std::string> args(std::deque<std::string>{
    "wrong",
    "tests/example/local_scene_example.toml",
    "10", "0", "35", "-1", "0", "-2",
    });
    cr_assert_str_eq(test_main(args), "Error: Parsing: Wrongs Args. Use ./interstonar --help");
}

Test(ParsingTest, NotAFile)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--local",
    "notAFile.toml",
    "10", "0", "35", "-1", "0", "-2",
    });
    cr_assert_str_eq(test_main(args), "Error: Parsing: notAFile.toml: No Such File.");
}

Test(ParsingTest, MissingTime)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--global",
    "tests/example/global_scene_example.toml",
    "10", "0", "35", "-1", "0", "-2",
    });
    cr_assert_str_eq(test_main(args), "Error: Parsing: Wrongs Args. Use ./interstonar --help");
}

Test(ParsingTest, NotANumberTime)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--global",
    "tests/example/global_scene_example.toml",
    "-d", "hello",
    "10", "0", "35", "-1", "0", "-2",
    });
    cr_assert_str_eq(test_main(args), "Error: Parsing: hello: Not a number.");
}

Test(ParsingTest, NotANumberInit)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--global",
    "tests/example/global_scene_example.toml",
    "-d", "1",
    "10", "hello", "35", "-1", "0", "-2",
    });
    cr_assert_str_eq(test_main(args), "Error: Parsing: hello: Not a number.");
}

Test(ParsingTest, ExtraArgs)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--global",
    "tests/example/global_scene_example.toml",
    "-d", "1",
    "10", "0", "35", "-1", "0", "-2",
    "extra"
    });
    cr_assert_str_eq(test_main(args), "Error: Parsing: Wrongs Args. Use ./interstonar --help");
}