#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    char *a = (char *)haystack;
    char *b = (char *)needle;
    int lenght = mx_strlen(needle);

    if (a == 0) {
        return b;
    }

    while (*a != 0) {
        if (!mx_strncmp(a, b, lenght)) {
            return a;
        }
        a++;
    }

    return NULL;
}

/*
int main() {
    char str[] = "How many time do you need?";
    char find[] = "time";

    char *ptr = mx_strstr(str, find);

    if (ptr) {
        printf("String is found\n");
    }
    else {
        printf("String was not found\n");
    }
}
*/

