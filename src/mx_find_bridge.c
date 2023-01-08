#include "../inc/header.h"

t_bridge *mx_find_bridge(const char *first, const char *second, t_bridge **bridges) {
    for (int i = 0; bridges[i] != NULL; i++) {
        if ((mx_strcmp(first, bridges[i]->start) == 0 && mx_strcmp(second, bridges[i]->finish) == 0)
        || (mx_strcmp(second, bridges[i]->start) == 0 && mx_strcmp(first, bridges[i]->finish) == 0)) {
            return bridges[i];
        }
    }
    
    return NULL;
}

