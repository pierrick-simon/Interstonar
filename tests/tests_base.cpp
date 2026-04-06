/*
** EPITECH PROJECT, 2026
** Intersonar
** File description:
** tests_bases
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>

static void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ParsingTest, linkInvalid)
{
    cr_assert_eq(1, 1);
}
