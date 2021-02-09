/*
** EPITECH PROJECT, 2024
** B_PSU_400_PAR_4_1_malloc_antoine_desruet
** File description:
** Created by antoine,
*/

#include "my_malloc.h"

static memory_t *find_smallest_block(memory_t *list, size_t size)
{
    memory_t *smallest = list;

    for (memory_t *tmp = list; tmp != NULL; tmp = tmp->next)
        if (tmp->size > size && tmp->size < smallest->size)
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
    int i = 0;
    for (memory_t *tmp = *list; tmp != NULL; tmp = tmp->next) {
        if (tmp->size >= size && tmp->size & 1) {
            tmp->size |= 0;
            return tmp + sizeof(tmp);
        }
        i++;
    }
    return NULL;
}

void *malloc(size_t size)
{
    static memory_t *list = NULL;
    int pages;

    size = adjust(size);
    if (list == NULL) {
        pages = nb_pages(size);
        list = sbrk(pages);
        list->size = pages;
        list->next = NULL;
    }
    memory_t *dest = find_smallest_block(list, size);
    if (dest == NULL) {
        pages = nb_pages(size);
        add_block(&list, sbrk(pages), size);
        dest = get_memory(&list, size);
    }
    return dest;
}