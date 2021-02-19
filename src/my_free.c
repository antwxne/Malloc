/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_free
*/

#include "my_malloc.h"

static void search_node(memory_t **list, const memory_t *node)
{
    for (memory_t *tmp = *list; tmp != NULL; tmp = tmp->next)
        if (tmp == node) {
            tmp->free = FREE;
            return;
        }
}

void free(void *ptr)
{
    memory_t *node = (void *)ptr;
    memory_t *list = stock_list(NULL);

    if (node == NULL)
        return;
    node = (void *)ptr - (sizeof(memory_t));
    if (node->free != NOT_FREE) {
        return;
    }
    search_node(&list, node);
    stock_list(list);
}
