/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-antoine.desruet
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <unistd.h>
#include <string.h>
#include <stdbool.h>

typedef struct memory {
    char free;
    size_t size;
    struct memory *next;
} memory_t;

enum plouf {
    END = 21,
    FREE = 42,
    NOT_FREE = 84
};

int nb_pages(size_t size);
size_t adjust(size_t size);

memory_t *stock_list(memory_t *list);

void *malloc(size_t size);

#endif /* !MY_MALLOC_H_ */
