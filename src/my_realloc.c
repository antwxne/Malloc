/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_realloc
*/

#include "my_malloc.h"

static bool check_merge(memory_t **ptr, size_t size)
{
    if ((*ptr)->next == NULL)
        return false;
    if ((*ptr)->size < size && (*ptr)->size + (*ptr)->next->size
        - sizeof(memory_t)> size) {
        (*ptr)->size += (*ptr)->next->size;
        (*ptr)->next = (*ptr)->next->next;
    }
    return true;
}

void *realloc(void *ptr, size_t size)
{
    void *dest;
    memory_t *tmp;

    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    tmp = (void *) ptr - sizeof(memory_t);
    if (tmp->size - sizeof(memory_t) >= size)
        return ptr;
    if (check_merge(&tmp, size)) {
        dest = malloc(size);
        if (dest == NULL)
            return NULL;
        dest = memcpy(dest, ptr, size);
        free(ptr);
        return dest;
    } else
        return (void *)tmp + sizeof(memory_t);
}
