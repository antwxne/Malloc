/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_reallocarray
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *dest = malloc(nmemb * size);

    dest = memcpy(dest, ptr, nmemb * size);
    free(ptr);
    return dest;
}
