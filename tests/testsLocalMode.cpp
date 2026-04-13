/*
** EPITECH PROJECT, 2026
** Interstonar
** File description:
** testsLocalMode
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

Test(SubjectTest, local_scene_example_intersection, .init = redirect_all_std)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--local",
    "tests/example/local_scene_example.toml",
    "10", "0", "35", "-1", "0", "-2",
    });
    cr_assert(test_main(args));
    fflush(stdout);
    cr_assert_stdout_eq_str(readFile("local_scene_example_intersection.txt", true).c_str());
}

Test(SubjectTest, local_scene_example_outOfScene, .init = redirect_all_std)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--local",
    "tests/example/local_scene_example.toml",
    "10", "0", "35", "-1", "-1", "-20",
    });
    cr_assert(test_main(args));
    fflush(stdout);
    cr_assert_stdout_eq_str(readFile("local_scene_example_outOfScene.txt", true).c_str());
}

Test(SubjectTest, infinite_cylinder, .init = redirect_all_std)
{
    std::queue<std::string> args(std::deque<std::string>{
    "--local",
    "tests/example/infinite_cylinder.toml",
    "3", "-6.2", "12", "0", "0", "10.3",
    });
    cr_assert(test_main(args));
    fflush(stdout);
    cr_assert_stdout_eq_str(readFile("infinite_cylinder.txt", true).c_str());
}
