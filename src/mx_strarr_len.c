#include "../inc/header.h"

int mx_strarr_len(char **arr) {
    if (arr == NULL) {
        return 0;
    }

    int length;
    for (length = 0; arr[length] != NULL; length++);
    
    return length;
}

