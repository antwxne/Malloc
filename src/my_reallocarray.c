/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_reallocarray
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *dest;
    size_t b;

    if (__builtin_mul_overflow(nmemb, size, &b))
        return NULL;
    dest  = malloc(b);
    if (dest != NULL) {
        dest = memcpy(dest, ptr, b);
        free(ptr);
    }
    return dest;
}
