#include "../inc/header.h"

void mx_dfs(int i, int **matrix, int *ranges, int count, t_list **ptr_paths) {
    t_list *temp;
    bool first = true;
    t_path_point *point;
    
    for (int j = 0; j < count; j++) {
        if (i == j) {
            continue;
        }

        if (ranges[i] > ranges[j] && ranges[i] - matrix[i][j] == ranges[j]) {
            if (!first) {
                for (temp = *ptr_paths; temp->next != NULL; temp = temp->next);

                point = malloc(sizeof(t_path_point));
                point->verticle = ((t_path_point*)((t_list*)temp->data)->data)->verticle;
                point->length = ((t_path_point*)((t_list*)temp->data)->data)->length;
                t_list *node = mx_create_node(point);

                if (((t_path_point*)node->data)->verticle != i) {
                    t_list *k = ((t_list*)temp->data)->next;

                    for (; k != NULL && ((t_path_point*)k->data)->verticle != i; k = k->next) {
                        point = malloc(sizeof(t_path_point));
                        point->verticle = ((t_path_point*)(k->data))->verticle;
                        point->length = ((t_path_point*)(k->data))->length;
                        mx_push_back(&node, point);
                    }

                    point = malloc(sizeof(t_path_point));
                    point->verticle = ((t_path_point*)(k->data))->verticle;
                    point->length = ((t_path_point*)(k->data))->length;
                    mx_push_back(&node, point);
                }

                mx_push_back(ptr_paths, node);
            }

            point = malloc(sizeof(t_path_point));
            point->verticle = j;
            point->length = ranges[j];

            for (temp = *ptr_paths; temp->next != NULL; temp = temp->next);
            
            temp = temp->data;
            mx_push_back(&temp, point);
            first = false;

            mx_dfs(j, matrix, ranges, count, ptr_paths);
        }
    }
}

t_list *mx_get_paths(int index, char **verticles, int **matrix, int *ranges, int count) {
    if (verticles != NULL) {
        
    }

    t_list *paths = NULL;

    for (int i = index + 1; i < count; i++) {
        t_path_point *point = malloc(sizeof(t_path_point));
        point->verticle = i;
        point->length = ranges[i];

        mx_push_back(&paths, mx_create_node(point));
        mx_dfs(i, matrix, ranges, count, &paths);
    }

    for (t_list *j = paths; j != NULL; j = j->next) {
        t_list *temp = NULL;

        for (t_list *k = j->data; k != NULL; k = k->next) {
            mx_push_front(&temp, k->data);
        }

        for (t_list *k = j->data; k != NULL;) {
            t_list *ptr = k;
            k = k->next;
            free(ptr);
            ptr = NULL;
        }

        j->data = temp;
    }

    return paths;
}

