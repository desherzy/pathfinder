#include "../inc/header.h"

int mx_add_verticle(char ***verticles, int length, const char *verticle) {
    for (int i = 0; i < length; i++) {
        if ((*verticles)[i] == NULL) {
            (*verticles)[i] = mx_strdup(verticle);
            
            return 0;
        }
        else if (mx_strcmp((*verticles)[i], verticle) == 0) {
            return -1;
        }
    }

    return -2;
}

