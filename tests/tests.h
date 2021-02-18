/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** tests
*/

#ifndef TESTS_H_
#define TESTS_H_

#include <unistd.h>

void my_free(void *ptr);

void *my_realloc(void *ptr, size_t size);

void *my_calloc(size_t nmemb, size_t size);

void *my_reallocarray(void *ptr, size_t nmemb, size_t size);

void *my_malloc(size_t size);

#endif /* !TESTS_H_ */
