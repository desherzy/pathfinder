#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub || !*str || !*sub) {
        return -2;
    }

    int index = 0;
    int lenght = mx_strlen(sub);

    while (*str) {
        if (mx_strncmp(str, sub, lenght) == 0) {
            return index;
        }

        str++;
        index++;
    }

    return -1;
}

/*
int main() {
    char str[] = "Hi mommy";
    char sub[] = "";

    printf("index is %i\n", mx_get_substr_index(str, sub));
}
*/

