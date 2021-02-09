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

int nb_pages(size_t size)
{
    int page_size = getpagesize() * 2;

    for (int page_ref = page_size; page_size < size; page_size += page_ref);
    return page_size;
}
