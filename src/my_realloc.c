#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *dest = malloc(size);

    dest = memcpy(dest, ptr, size);
    free(ptr);
    return dest;
}
