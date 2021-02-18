/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "tests.h"
#include "my_malloc.h"

Test(malloc, test1)
{
    char *ptr = my_malloc(5);

    ptr = strcpy(ptr, "toto");
    cr_expect_str_eq(ptr, "toto");
}