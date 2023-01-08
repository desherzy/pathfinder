#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *str = (unsigned char *)b;

    for (size_t i = 0; i < len; i++) {
        str[i] = (unsigned char)c;
    }

    return b;
}

/*
int main() {
    char str[] = "Hello someone from the other side";
    size_t lenght = mx_strlen(str);

    printf("before : %s\n", str);

    char *new = mx_memset(str, '.', lenght);

    printf("after : %s\n", new);

    printf("len of 'new' : %i\n", mx_strlen(new));
}
*/

