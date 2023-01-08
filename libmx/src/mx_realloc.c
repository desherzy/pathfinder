#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == 0) {
        return malloc(size);
    }

    size_t lenght;
    #if defined(__MACH__)
    lenght = malloc_size(ptr); // mac
    #else
    lenght = malloc_usable_size(ptr); // linux
    #endif

    if (size <= lenght) {
        return ptr;
    }

    void *temp = malloc(size);
    mx_memcpy(temp, ptr, lenght);
    free(ptr);
    return temp;
}

