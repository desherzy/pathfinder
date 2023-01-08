#include "../inc/header.h"

int mx_read_bridge(const char *line, t_bridge **bridge) {
    char** values = mx_strsplit(line, '-');

    if (mx_strarr_len(values) != 2 || mx_strlen(values[1]) == 0
    || mx_strlen(values[0]) + mx_strlen(values[1]) != mx_strlen(line) - 1) {
        mx_del_strarr(&values);
        return -1;
    }

    char** end = mx_strsplit(values[1], ',');
    
    if (mx_strarr_len(end) != 2 || mx_strcmp(values[0], end[0]) == 0) {
        mx_del_strarr(&values);
        mx_del_strarr(&end);
        return -2;
    }
    
    char* num_line = mx_strdup(end[1]);
    *bridge = malloc(sizeof(t_bridge));
    (*bridge)->start = mx_strdup(values[0]);
    (*bridge)->finish = mx_strdup(end[0]);
    (*bridge)->length = mx_atoi(num_line);
    
    mx_del_strarr(&values);
    mx_del_strarr(&end);
    mx_strdel(&num_line);
    
    if ((*bridge)->length <= 0) {
        mx_del_bridge(bridge);
        return -3;
    }
    
    return 0;
}

