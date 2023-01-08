#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *node = mx_create_node(data);
    node->next = *list;
    *list = node;
}

/*
int main() {
    int num1 = 121;
    int num2 = 144;
    t_list *head = mx_create_node(&num1);
    mx_push_front(&head, &num2);
    printf("%d\n", *(int *)head->data);
    printf("%d\n", *(int *)head->next->data);
    printf("%s\n", (char *)head->next->next);
}
*/

