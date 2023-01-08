#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *node = mx_create_node(data);
    t_list *current = *list;

    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = node;
    }
    else {
        *list = node;
    }
}

/*
int main() {
    char *data1 = "Adele";
    char *data2 = "Hello";
    char *data3 = "It's me";

    t_list *head = mx_create_node(data1);
    mx_push_back(&head, data2);
    printf("%s\n", (char *)head->data);
    printf("%s\n", (char *)head->next->data);
    mx_push_back(&head, data3);
    printf("%s\n", (char *)head->next->next->data);
}
*/

