/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_calloc
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc((nmemb + 1) * size);

    if (ptr == NULL)
        return NULL;
    ptr = memset(ptr, 0, (nmemb + 1) * size);
    return ptr;
}
