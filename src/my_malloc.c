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

void *best_fit(memory_t **list, size_t size)
{
    size_t min = 0;
    memory_t *dest = NULL;


    for (memory_t *tmp = *list; tmp != NULL; tmp = tmp->next)
        if (tmp->size > min && tmp->free == FREE && tmp->size >= size) {
            dest = tmp;
            dest->free = NOT_FREE;
        }
    return dest;
}

bool adjust_heap(memory_t **end, size_t size)
{
    int pages = nb_pages(size);

    if (sbrk(pages) == (void *) -1)
        return false;
    (*end)->next = NULL;
    (*end)->free = END;
    (*end)->size += (size_t)pages;
    return true;

    return true;
}

void *add_block(memory_t **list, size_t size)
{
    memory_t *tmp = *list;
    size_t adjusted_size = adjust(size);

    for (; tmp->free != END; tmp = tmp->next);
    if (tmp->size < adjusted_size)
        if(!adjust_heap(&tmp, size))
            return NULL;
    tmp->next = (memory_t *)((void *)tmp + sizeof(memory_t)
                             + adjusted_size + 1);
    *(tmp->next) = (memory_t){END, tmp->size - adjusted_size + 1
                              - sizeof(memory_t), NULL};
    tmp->size = adjusted_size;
    tmp->free = NOT_FREE;
    return tmp;
}

static void fils_de_pute(memory_t *list)
{
    for (memory_t *tmp = list; tmp != NULL; tmp = tmp->next)
        if (tmp->free != END && tmp->free != FREE && tmp->free != NOT_FREE)
            abort();
}

void *malloc(size_t size)
{
    memory_t *list = stock_list(NULL);
    memory_t *dest = NULL;

    if (list == NULL)
        if (!init_list(&list, size))
            return NULL;
    fils_de_pute(list);
    dest = best_fit(&list, size);
    if (dest == NULL)
        dest = add_block(&list, size);
    stock_list(list);
    return (void *)dest + sizeof(memory_t);
}
