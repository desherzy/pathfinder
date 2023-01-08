#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    t_list *node = *head;

    if (head == NULL || *head == NULL) {
        return;
    }

    while (node->next != NULL) {
        node = node->next;
    }

    if (node != NULL) {
        free(node->next);
        node->next = NULL;
    }
    else {
        free(*head);
        *head = NULL;
    }
}

