#include "my_malloc.h"

memory_t *stock_list(memory_t *list)
{
    static memory_t *stock = NULL;

    if (list != NULL)
        stock = list;
    return stock;
}
