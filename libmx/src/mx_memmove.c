#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *s1 = (unsigned char *)src;
    unsigned char *s2 = malloc(len);

    for (size_t i = 0; i < len; i++) {
        s2[i] = s1[i];
    }

    dst = mx_memcpy(dst, s2, len);

    free(s2);
    return dst;
}

/*
int main() {
    char dst[] = "gigaCHAD";
    char src[] = "mi me ma mo mu";

    printf("Before | dst : %s | src : %s\n", dst, src);

    mx_memmove(dst, src, 15);

    printf("After | dst : %s | src : %s\n", dst, src);
}
*/

