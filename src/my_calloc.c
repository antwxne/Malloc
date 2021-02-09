#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    ptr = memset(ptr, 0, nmemb * size);
    return ptr;
}
