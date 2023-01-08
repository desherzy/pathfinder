#include "../inc/header.h"

int mx_read_bridges(char *content, t_bridge ***bridges, char ***verticles, int *count) {
    char **lines = mx_strsplit(content, '\n');
    *count = mx_atoi(lines[0]);
    
    if (*count <= 0) {
        mx_del_strarr(&lines);
        mx_printerr("error: line 1 is not valid\n");
        
        return -1;
    }

    int error;
    int length = mx_strarr_len(lines);
    (*bridges) = malloc(length * sizeof(t_bridge*));

    for (int i = 0; i < length; i++) {
        (*bridges)[i] = NULL;
    }

    for (int i = 1; lines[i] != NULL; i++) {
        if ((error = mx_read_bridge(lines[i], &(*bridges)[i - 1])) < 0) {
            mx_del_strarr(&lines);
            mx_printerr("error: line ");
            char *num = mx_itoa(i + 1);
            mx_printerr(num);
            mx_strdel(&num);
            mx_printerr(" is not valid\n");

            for (i--; i > 0; i--) {
                mx_del_bridge(&(*bridges)[i - 1]);
            }

            free(*bridges);
            *bridges = NULL;
            
            return -2;
        }
    }

    mx_del_strarr(&lines);

    (*verticles) = malloc(sizeof(char*) * ((*count) + 1));

    for (int i = 0; i <= *count; i++) {
        (*verticles)[i] = NULL;
    }

    for (int i = 0; (*bridges)[i] != NULL; i++) {
        if (mx_add_verticle(verticles, *count, (*bridges)[i]->start) == -2
        || mx_add_verticle(verticles, *count, (*bridges)[i]->finish) == -2) {
            mx_del_strarr(verticles);

            for (int j = 0; (*bridges)[j] != NULL; j++) {
                mx_del_bridge(&(*bridges)[j]);
            }

            free(*bridges);
            *bridges = NULL;
            mx_printerr("error: invalid number of islands\n");
            
            return -3;
        }
    }

    for (int i = 0; (*bridges)[i] != NULL; i++) {
        for (int j = i + 1; (*bridges)[j] != NULL; j++) {
            if ((mx_strcmp((*bridges)[i]->start, (*bridges)[j]->start) == 0 && mx_strcmp((*bridges)[i]->finish, (*bridges)[j]->finish) == 0)
            || (mx_strcmp((*bridges)[i]->start, (*bridges)[j]->finish) == 0 && mx_strcmp((*bridges)[i]->finish, (*bridges)[j]->start) == 0)) {
                mx_del_strarr(verticles);

                for (int j = 0; (*bridges)[j] != NULL; j++) {
                    mx_del_bridge(&(*bridges)[j]);
                }

                free(*bridges);
                *bridges = NULL;
                mx_printerr("error: duplicate bridges\n");
                
                return -4;
            }
        }
    }

    for (int i = 0, sum = 0; (*bridges)[i] != NULL; i++) {
        if (INT_MAX - (*bridges)[i]->length < sum) {
            mx_del_strarr(verticles);

            for (int j = 0; (*bridges)[j] != NULL; j++) {
                mx_del_bridge(&(*bridges)[j]);
            }

            free(*bridges);
            *bridges = NULL;
            mx_printerr("error: sum of bridges lengths is too big\n");
            
            return -5;
        }

        sum += (*bridges)[i]->length;
    }
    
    return 0;
}

