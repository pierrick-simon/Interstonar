/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** testsGlobalMode
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

#include "InterException.hpp"
#include "Interstonar.hpp"

static void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static const bool test_main(std::queue<std::string> args)
{
    try {
        inter::Interstonar interstonar(args);
        interstonar.run();
    } catch (inter::InterException _) {
        return false;
    }
    return true;
}

static std::string readFile(const char *name, bool test)
{
    char path[1024] = "";
    if (test)
        strcat(path, "tests/testResult/");
    strcat(path, name);

    std::ifstream file(path);
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

Test(SubjectTest, global_scene_exemple, .init = redirect_all_std)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--global",
    "tests/example/global_scene_example.toml",
    "--delta=3600",
    "1", "2", "3", "4", "5", "6",
    });
    cr_assert(test_main(args));
    fflush(stdout);
    cr_assert_stdout_eq_str(readFile("global_scene_exemple.txt", true).c_str());
}

Test(SubjectTest, global_scene_exemple_fail, .init = redirect_all_std)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--global",
    "tests/example/global_scene_example.toml",
    "--delta=5000",
    "1", "2", "3", "4", "5", "6",
    });
    cr_assert(test_main(args));
    fflush(stdout);
    cr_assert_stdout_eq_str(readFile("global_scene_exemple_fail.txt", true).c_str());
}
