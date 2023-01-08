#include "../inc/header.h"

void mx_print_path(t_list *path, char **verticles) {
    char *temp = NULL;
    char *path_str = mx_strjoin(verticles[((t_path_point*)path->data)->verticle], " -> ");
    char *route_str = mx_strdup(verticles[((t_path_point*)path->data)->verticle]);
    int last_len = ((t_path_point*)path->next->data)->length;
    char *dist_str = mx_itoa(last_len);

    for (t_list *i = path->next; i != NULL; i = i->next) {
        t_path_point *point = i->data;
        temp = route_str;
        route_str = mx_strjoin(route_str, " -> ");
        mx_strdel(&temp);
        temp = route_str;
        route_str = mx_strjoin(route_str, verticles[point->verticle]);
        mx_strdel(&temp);

        if (i->next == NULL) {
            temp = path_str;
            path_str = mx_strjoin(path_str, verticles[point->verticle]);
            mx_strdel(&temp);

            if (mx_atoi(dist_str) == 0) {
                temp = dist_str;
                dist_str = mx_strjoin(dist_str, " = ");
                mx_strdel(&temp);
                temp = dist_str;
                char *num = mx_itoa(point->length);
                dist_str = mx_strjoin(dist_str, num);
                mx_strdel(&num);
                mx_strdel(&temp);
            }
        }
        else {
            point = i->next->data;
            temp = dist_str;
            dist_str = mx_strjoin(dist_str, " + ");
            mx_strdel(&temp);
            temp = dist_str;
            char *num = mx_itoa(point->length - last_len);
            last_len = point->length;
            dist_str = mx_strjoin(dist_str, num);
            mx_strdel(&num);
            mx_strdel(&temp);
        }
    }
    
    mx_printstr("========================================");
    mx_printstr("\nPath: ");
    mx_printstr(path_str);
    mx_strdel(&path_str);
    mx_printstr("\nRoute: ");
    mx_printstr(route_str);
    mx_strdel(&route_str);
    mx_printstr("\nDistance: ");
    mx_printstr(dist_str);
    mx_strdel(&dist_str);
    mx_printstr("\n========================================\n");
}

