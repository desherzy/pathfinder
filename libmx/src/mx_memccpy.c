#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    for (size_t i = 0; i < n; i++) {
        ((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];

        if (((const unsigned char *)src)[i] == (unsigned char)c) {
            return (void *)&(((unsigned char *)dst)[i + 1]);
        }
    }

    return NULL;
}

/*
int main() {
    char src[] = "Text to copy * <- after this not gonna copy";
    char dst[20];
    size_t lenght = mx_strlen(src);

    mx_memccpy(dst, src, '*', lenght);
    printf("dst after memccpy: %s\n", dst);
}
*/

