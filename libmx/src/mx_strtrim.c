#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int i;
    int counter = 0;
    for (i = 0; mx_isspace(str[i]); i++) {
        counter++;
    }
    
    int lenght = mx_strlen(str);
    for (int j = lenght - 1; mx_isspace(str[j]); j--) {
        counter++;
    }
    
    char *string = mx_strnew(lenght - counter);
    if (string == NULL) {
        return NULL;
    }

    mx_strncpy(string, str + i, lenght - counter);
    return string;
}

/*
int main() {
    char str[] = {"    Trim    "};
    char *ptr = mx_strtrim(str);
    printf("%s\n", ptr);
    mx_strdel(&ptr);
}
*/

