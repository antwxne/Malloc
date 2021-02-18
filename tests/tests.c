/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "tests.h"
#include "my_malloc.h"

Test(malloc, test_small)
{
    char *ptr = my_malloc(5);

    ptr = strcpy(ptr, "toto");
    cr_expect_str_eq(ptr, "toto");
}

Test(malloc, test_medium)
{
    char *ptr = my_malloc(500);

    for (int i = 0; i < 500; i++)
        ptr[i] = 'a';
}

Test(malloc, test_big)
{
    char *ptr = my_malloc(1000);

    for (int i = 0; i < 1000; i++)
        ptr[i] = 'a';
}

Test(malloc, test_very_big)
{
    char *ptr = my_malloc(100000000);

    for (int i = 0; i < 100000000; i++)
        ptr[i] = 'a';
}

Test(malloc, test_multiple_malloc)
{
    char **ptr = my_malloc(100 * sizeof(char *));

    for (int i = 0; i < 100; i++) {
        ptr[i] = my_malloc(1000 * sizeof(char));
        for (int x = 0; x < 1000; x++)
            ptr[i][x] = 'a';
    }
}

Test(calloc, test_small)
{
    char *ptr = my_calloc(5, 1);

    ptr = strcpy(ptr, "toto");
    cr_expect_str_eq(ptr, "toto");
}

Test(calloc, test_medium)
{
    char *ptr = my_calloc(500, 1);

    for (int i = 0; i < 500; i++)
        ptr[i] = 'a';
}

Test(calloc, test_big)
{
    char *ptr = my_calloc(1000, 1);

    for (int i = 0; i < 1000; i++)
        ptr[i] = 'a';
}

Test(calloc, test_very_big)
{
    char *ptr = my_calloc(100000000, 1);

    for (int i = 0; i < 100000000; i++)
        ptr[i] = 'a';
}

Test(calloc, test_multiple_calloc)
{
    char **ptr = my_calloc(100, sizeof(char *));

    for (int i = 0; i < 100; i++) {
        ptr[i] = my_calloc(1000, sizeof(char));
        for (int x = 0; x < 1000; x++)
            ptr[i][x] = 'a';
    }
}

Test(realloc, null)
{
    char* ptr = NULL;

    ptr = my_realloc(ptr, 5);
    ptr[4] = 'a';
    cr_expect_eq(ptr[4], 'a');
}

Test(realloc, small)
{
    char* ptr = malloc(6);

    ptr = my_realloc(ptr, 90);
    ptr[80] = 'a';
    cr_expect_eq(ptr[80], 'a');
}

Test(reallocarray, normal)
{
    char* ptr = malloc(6);

    ptr = reallocarray(ptr, 80, 1);
    ptr[70] = 'a';
    cr_expect_eq(ptr[70], 'a');
}

Test(reallocarray, null)
{
    char* ptr = NULL;

    ptr = my_reallocarray(ptr, 80, 1);
    ptr[70] = 'a';
    cr_expect_eq(ptr[70], 'a');
}

Test(reallocarray, overflow)
{
    char* ptr = NULL;

    ptr = my_reallocarray(ptr, 800000000000, 2000000000000);
    cr_expect_null(ptr);
}

Test(calloc, overflow)
{
    char* ptr = NULL;

    ptr = my_calloc(800000000000, 2000000000000);
    cr_expect_null(ptr);
}

Test(malloc, bestfit)
{
    void *ptr1 = my_malloc(5);
    void *ptr2 = my_malloc(10);
    void *ptr3 = my_malloc(20);
    size_t ref = (size_t) ptr2;

    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);
    ptr1 = my_malloc(10);
    cr_expect_eq(ref, ptr1);
}