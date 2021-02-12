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
    return;
    fprintf(stderr, "free(): invalid pointer.\n");
    abort();
}

static void merge_block(memory_t **list)
{
    memory_t *tmp = *list;


    if (tmp->next == NULL)
        return;
    if (tmp->next->free == END) {
        tmp->size += tmp->next->size;
        tmp->free = tmp->next->free;
        tmp->next = NULL;
    }
    for (; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->next != NULL && tmp->free == FREE
            && tmp->next->free == FREE) {
            tmp->size += tmp->next->size;
            tmp->free = tmp->next->free;
            tmp->next = tmp->next->next;
        }
    }
}

void free(void *ptr)
{
    memory_t *node = (void *)ptr - (sizeof(memory_t));
    memory_t *list = stock_list(NULL);

    if (node == NULL || node->free != NOT_FREE) {
        return;
        fprintf(stderr, "free(): invalid pointer.\n");
        abort();
    }
    search_node(&list, node);
    merge_block(&list);
    stock_list(list);
}
