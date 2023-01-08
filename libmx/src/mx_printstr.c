#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    int lenght = mx_strlen(s);

    write(1, s, lenght);
}

