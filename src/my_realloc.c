/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_realloc
*/

#include "my_malloc.h"

/* static void search_node(memory_t **list, const memory_t *node) */
/* { */
/*     for (memory_t *tmp = *list; tmp != NULL; tmp = tmp->next) */
/*         if (tmp == node) { */
/*             tmp->free = FREE; */
/*             return; */
/*         } */
/*     return; */
/*     fprintf(stderr, "free(): invalid pointer.\n"); */
/*     abort(); */
/* } */

void *realloc(void *ptr, size_t size)
{
    void *dest;
    memory_t *tmp;

    if (size == 0)
        return NULL;
    tmp = (void *) ptr - sizeof(memory_t);
    if (tmp->size < size) {
        dest = malloc(size);
        dest = memcpy(dest, ptr, size);
        free(ptr);
        return dest;
    } else
        return ptr;
}
