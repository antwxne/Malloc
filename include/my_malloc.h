/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <stdbool.h>
#include <unistd.h>
#include <string.h>

typedef struct memory {
    size_t size;
    struct memory *next;
} memory_t;

int nb_pages(size_t size);
size_t adjust(size_t size);

void *malloc(size_t size);

#endif /* !MY_MALLOC_H_ */
