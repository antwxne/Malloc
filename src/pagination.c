/*
** EPITECH PROJECT, 2024
** B_PSU_400_PAR_4_1_malloc_antoine_desruet
** File description:
** Created by antoine,
*/

#include "my_malloc.h"

size_t adjust(size_t size)
{
    size_t dest = 1 << 1;
    size_t tmp = dest;
    size_t i = 1;

    while (size + sizeof(memory_t) > dest) {
        dest = tmp * i;
        i++;
    }
    return dest;
}

static bool adjust_heap(memory_t **end)
{
    if (sbrk(getpagesize() * 24) == (void *) -1)
        return false;
    (*end)->next = NULL;
    (*end)->free = END;
    (*end)->size += (size_t)getpagesize() * 24;
    return true;
}

void *add_block(memory_t **list, size_t size)
{
    memory_t *tmp = *list;
    size_t adjusted_size = adjust(size);

    for (;tmp && tmp->free != END; tmp = tmp->next);
    if (tmp == NULL)
        if (init_list(&tmp, size) == false)
            return NULL;
    if (tmp->size <= adjusted_size)
        if (!adjust_heap(&tmp))
            return NULL;
    tmp->next = (memory_t *)((void *)tmp + adjusted_size);
    *(tmp->next) = (memory_t){END, tmp->size - adjusted_size
                            , NULL};
    tmp->size = adjusted_size;
    tmp->free = NOT_FREE;
    return tmp;
}

int nb_pages(size_t size)
{
    int page_size = getpagesize() * 2;

    for (int page_ref = page_size; page_size <
        (int)size; page_size += page_ref);
    return page_size;
}
