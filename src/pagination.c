/*
** EPITECH PROJECT, 2024
** B_PSU_400_PAR_4_1_malloc_antoine_desruet
** File description:
** Created by antoine,
*/

#include "my_malloc.h"

size_t adjust(size_t size)
{
    size_t dest = 0;
    size_t i = 4;

    while (size > dest) {
        dest = 1 << i;
        i++;
    }
    return dest;
}

static bool adjust_heap(memory_t **end, size_t size)
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

int nb_pages(size_t size)
{
    int page_size = getpagesize() * 2;

    for (int page_ref = page_size; page_size < (int)size; page_size += page_ref);
    return page_size;
}
