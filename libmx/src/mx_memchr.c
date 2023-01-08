#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *str = (unsigned char *)s;

    while (n != 0) {
        if (*str == (unsigned char)c) {
            return str;
        }

        str++;
        n--;
    }

    return NULL;
}

/*
int main() {
    char str[] = "abcdifghijklmnopqrstuvwxyz";
    size_t lenght = mx_strlen(str);

    printf("str : %s\n", mx_memchr(str, 'm', lenght));
}
*/

