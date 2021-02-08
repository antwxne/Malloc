#include <dlfcn.h>

void my_putstr(char *str);

int main(void)
{
    void (*plouf)(char *);

    void *handle = dlopen("./libmalloc.so", RTLD_LAZY);
    if (!handle)
        return 84;
    plouf = (void (*)(char *))dlsym(handle, "my_putstr");
    plouf("Hello World!!!\n");
    dlclose(handle);
    return 0;
}
