#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *dest = malloc(nmemb * size);

    dest = memcpy(dest, ptr, nmemb * size);
    free(ptr);
    return dest;
}
