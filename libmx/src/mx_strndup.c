#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t lenght = mx_strlen(s1);

    if (n <= 0 || n > lenght) {
        return NULL;
    }

    char *dst = mx_strnew(n);
    mx_strncpy(dst, s1, n);

    return dst;
}

/*
int main() {
    char str[] = "Hello daddy";
    char *dup = mx_strndup(str, 10);

    printf("dup is : %s\n", dup);
}
*/

