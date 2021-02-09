/*
** EPITECH PROJECT, 2024
** B_PSU_400_PAR_4_1_malloc_antoine_desruet
** File description:
** Created by antoine,
*/

#include "my_malloc.h"

static memory_t *find_smallest_block(memory_t *list, size_t size)
{
    memory_t *smallest = {0, NULL};

    for (memory_t *tmp = list ; tmp; tmp = tmp->next)
        if (tmp->size > size && (tmp->size < smallest->size || smallest->size == 0))
            smallest = tmp;
    return smallest->size == 0 ? NULL : smallest;
}

static void add_block(memory_t **list, void *ptr, size_t size)
{
    for (memory_t *tmp = *list; tmp; tmp = tmp->next) {
        if (tmp->next == NULL) {
            tmp->next = (memory_t *)((void *)tmp + sizeof(tmp) + tmp->size);
            *tmp->next = (memory_t){size, NULL};
            return;
        }
    }
}

static void *get_memory(memory_t **list, size_t size)
{
    for (memory_t *tmp = *list; tmp != NULL; tmp = tmp->next) {
        if (tmp->size >= size && tmp->size & 1) {
            tmp->size |= 0;
            return tmp + sizeof(tmp);
        }
    }
    return NULL;
}

static size_t adjust(size_t size)
{
    size_t dest = 0;
    size_t i = 4;

    while (size > dest) {
        dest = 1 << i;
        i++;
    }
    return dest;
}

static int nb_pages(size_t size)
{
    int page_size = getpagesize() * 2;

    for (int page_ref = page_size; page_size < size; page_size += page_ref);
    return page_size;
}

void *my_malloc(size_t size)
{
    static memory_t *list = {0, NULL};
    memory_t *dest = find_smallest_block(list, size);

    size = adjust(size);
    if (dest == NULL) {
        add_block(&list, sbrk(nb_pages(size)), size);
        dest = get_memory(&list, size);
    }
    return dest;
}