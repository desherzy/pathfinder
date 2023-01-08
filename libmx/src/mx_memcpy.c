#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    for (size_t i = 0; i < n; i++) {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
    }

    return dst;
}

/*
int main() {
    char str[] = "Hello, it's me - Adele";
    size_t lenght = mx_strlen(str);

    printf("Source : %s\n", str);

    char copy[] = "Lulyakebab man";      //mx_memcpy(copy, str, lenght);
    mx_memcpy(copy, str, lenght);

    printf("Copy : %s\n", copy);
}
*/

