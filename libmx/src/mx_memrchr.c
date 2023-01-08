#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    int lenght = mx_strlen(s);
    unsigned char *str = (unsigned char *)s + lenght;

    while (n != 0) {
        if (*str == (unsigned char)c) {
            return str;
        }

        str--;
        n--;
    }

    return NULL;
}

/*
int main() {
    char str[] = "abcdifghijklmnopqrstuvwxyz";
    size_t lenght = mx_strlen(str);

    printf("str : %s\n", mx_memrchr(str, 'm', lenght));
}
*/

