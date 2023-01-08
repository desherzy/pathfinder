#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) {
        return NULL;
    }
    
    int length = 0;
    int i = 0;
    char **str = NULL;

    str = (char**)malloc((mx_count_words(s, c) + 1) * sizeof(char*));

    while ((*s) && (*s != '\0')) {
        if (*s != c) {

            length = 0;
            while (s[length] && s[length] != c) 
                length++;

            str[i] = mx_strndup(s, length);
            s += length;
            i++;
            
            continue;
        }
        s++;
    }
    str[i] = NULL;
    return str;
}
