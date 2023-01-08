#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    int lenght = mx_strlen(str);
    if (lenght < 0) {
        return NULL;
    }

    char *dst = mx_strnew(lenght);
    mx_strcpy(dst, str);

    return dst;
}

