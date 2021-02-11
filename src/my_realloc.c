#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *dest;
    memory_t *tmp = (void *) ptr - sizeof(memory_t);

    if (tmp->size < size) {
        dest = malloc(size);
        dest = memcpy(dest, ptr, size);
        free(ptr);
        return dest;
    } else
        return ptr;
}
