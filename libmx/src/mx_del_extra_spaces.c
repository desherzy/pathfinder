#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) {
        return NULL;
    }

    int lenght = mx_strlen(str);
    char *temp = mx_strnew(lenght);

    int j = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (!mx_isspace(str[i])) {
            temp[j] = str[i];
            j++;
        }

        if (!mx_isspace(str[i]) && mx_isspace(str[i + 1])) {
            temp[j] = ' ';
            j++;
        }
    }

    char *new = mx_strtrim(temp);
    mx_strdel(&temp);

    return new;
}

/*
int main() {
    char str[] = "Some    extra     spaces     is     here";

    printf("before : %s\n", str);

    printf("after : %s\n", mx_del_extra_spaces(str));
}
*/

