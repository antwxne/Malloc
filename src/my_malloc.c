/*
** EPITECH PROJECT, 2024
** B_PSU_400_PAR_4_1_malloc_antoine_desruet
** File description:
** Created by antoine,
*/

#include "my_malloc.h"

static bool init_list(memory_t **list, size_t size)
{
    int pages = nb_pages(size);

    *list = sbrk(pages);
    if (list == (void *) -1)
        return false;
    (*list)->next = NULL;
    (*list)->free = END;
    (*list)->size = (size_t)pages;
    stock_list(*list);
    return true;
}

static void *best_fit(memory_t **list, size_t size)
{
    size_t min = 0;
    memory_t *dest = NULL;


    for (memory_t *tmp = *list; tmp != NULL; tmp = tmp->next)
        if (tmp->size > min && tmp->free == FREE && tmp->size >= size) {
            dest = tmp;
            dest->free = NOT_FREE;
            min = dest->size;
        }
    return dest;
}

static void check_if_user_has_rewrite(memory_t *list)
{
    for (memory_t *tmp = list; tmp != NULL; tmp = tmp->next)
        if (tmp->free != END && tmp->free != FREE && tmp->free != NOT_FREE)
            abort();
}

void *malloc(size_t size)
{
    memory_t *list = stock_list(NULL);
    memory_t *dest = NULL;

    if (size == 0)
        return NULL;
    if (list == NULL)
        if (!init_list(&list, size))
            return NULL;
    check_if_user_has_rewrite(list);
    dest = best_fit(&list, size);
    if (dest == NULL) {
        dest = add_block(&list, size);
        if (dest == NULL)
            return NULL;
    }
    stock_list(list);
    return (void *)dest + sizeof(memory_t);
}
