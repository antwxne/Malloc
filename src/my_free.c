#include "my_malloc.h"

static void search_node(memory_t **list, const memory_t *node)
{
    for (memory_t *tmp = *list; tmp != NULL; tmp = tmp->next)
        if (tmp == node) {
            tmp->free = FREE;
            return;
        }
    fprintf(stderr, "Free: invalid pointer.\n");
    abort();
}

static void merge_block(memory_t **list)
{
    memory_t *tmp = *list;
    int merged = 0;


    if (tmp->next == NULL)
        return;
    if (tmp->next->free == END) {
        tmp->size += tmp->next->size;
        tmp->free = tmp->next->free;
        tmp->next = NULL;
    }
    for (; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->next != NULL && tmp->free == FREE
            && tmp->next->free == FREE) {
            tmp->size += tmp->next->size;
            tmp->free = tmp->next->free;
            merged += 1;
            tmp->next = tmp->next->next;
        }
    }
}

void free(void *ptr)
{
    memory_t *node = (void *)ptr - (sizeof(memory_t));
    memory_t *list = stock_list(NULL);

    if (node == NULL || node->free != NOT_FREE) {
        fprintf(stderr, "Free: invalid pointer acsac.\n");
        abort();
    }
    search_node(&list, node);
    merge_block(&list);
    stock_list(list);
}
