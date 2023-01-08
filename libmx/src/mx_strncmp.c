#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    while (n != 0) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }

        s1++;
        s2++;
        n--;
    }

    return 0;
}

