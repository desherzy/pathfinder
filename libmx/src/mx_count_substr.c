#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub || !*str || !*sub) {
        return -1;
    }

    int counter = 0;

    if (*sub) {
        int lenght = mx_strlen(sub);

        while (*str) {
            if (mx_strncmp(str, sub, lenght) == 0) {
                counter++;
            }

            str++;
        }
    }

    return counter;
}

/*
int main() {
    char str[] = "niko niko man";
    char sub[] = "niko";

    printf("counter : %i\n", mx_count_substr(str, sub));
}
*/

