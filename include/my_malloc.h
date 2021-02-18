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
#include <stdio.h>
#include <stdlib.h>

#ifdef TU
#define free my_free
#define realloc my_realloc
#define malloc my_malloc
#define reallocarray my_reallocarray
#define calloc my_calloc
#endif

typedef struct __attribute__((__packed__, aligned(2))) memory {
    char free;
    size_t size;
    struct memory *next;
} memory_t;

enum magic {
    END = -21,
    FREE = -42,
    NOT_FREE = -84
};

int nb_pages(size_t size);
size_t adjust(size_t size);
bool init_list(memory_t **list, size_t size);
void *add_block(memory_t **list, size_t size);

memory_t *stock_list(memory_t *list);

void free(void *ptr);

void *realloc(void *ptr, size_t size);

void *my_calloc(size_t nmemb, size_t size);

void *reallocarray(void *ptr, size_t nmemb, size_t size);

void *malloc(size_t size);

#endif /* !MY_MALLOC_H_ */
