#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *a, void *b)) {
    t_list *i = lst;
    while (i != NULL) {
        i = i->next;

        for (t_list *j = lst; j->next != NULL; j = j->next) {
            if (cmp(j->data, j->next->data)) {
                void *sort = j->data;
                j->data = j->next->data;
                j->next->data = sort;
            }
        }
    }
    return lst;
}

