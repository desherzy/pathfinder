#pragma once

#include "../libmx/inc/libmx.h"
#include <limits.h>

typedef struct  s_bridge {
    char *start;
    int length;
    char *finish;
} t_bridge;

typedef struct  s_path_point {
    int verticle;
    int length;
} t_path_point;

int mx_strarr_len(char **arr);

//1
int mx_check_usage_error(int argc);
int mx_get_file_content(const char* filename, char **content);
int mx_add_verticle(char ***verticles, int length, const char *verticle);
int mx_read_bridges(char *content, t_bridge ***bridges, char ***verticles, int *count);
int mx_read_bridge(const char *line, t_bridge **bridge);
void mx_del_bridge(t_bridge **bridge);

//2
int **mx_create_adj_matrix(char **verticles, int count, t_bridge **bridges);
t_bridge *mx_find_bridge(const char *first, const char *second, t_bridge **bridges);
int *mx_dijkstra(int **matrix, int count, int index);
t_list *mx_get_paths(int index, char **verticles, int **matrix, int *ranges, int count);
void mx_print_path(t_list *path, char **verticles);

