/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_realloc
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *dest;
    memory_t *tmp = (void *) ptr - sizeof(memory_t);

    if (tmp->size < size) {
        dest = malloc(size);
        dest = memcpy(dest, ptr, size);
        free(ptr);
        return dest;
    } else
        return ptr;
}
