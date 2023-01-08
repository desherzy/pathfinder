#include "../inc/header.h"

int **mx_create_adj_matrix(char **verticles, int count, t_bridge **bridges) {
    if (verticles == NULL || bridges == NULL) {

    }

    int **bridges_matrix = malloc(sizeof(int*) * count);

    for (int i = 0; i < count; i++) {
        bridges_matrix[i] = malloc(sizeof(int) * count);

        for (int j = 0; j < count; j++) {
            bridges_matrix[i][j] = i == j ? 0 : -1;
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (i == j) {
                continue;
            }

            t_bridge *temp = mx_find_bridge(verticles[i], verticles[j], bridges);
            if (temp != NULL) {
                //printf("%s -> %d -> %s\n", temp->start, temp->length, temp->finish);
                bridges_matrix[i][j] = temp->length;
            }
        }
    }

    return bridges_matrix;
}

