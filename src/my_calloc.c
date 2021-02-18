/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_calloc
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;
    size_t b;

    if (__builtin_mul_overflow(nmemb, size, &b))
        return NULL;
    ptr = malloc(b);
    b = adjust(b) - sizeof(memory_t);
    if (ptr == NULL)
        return NULL;
    ptr = memset(ptr, 0, b);
    return ptr;
}
