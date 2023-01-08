#include "../inc/header.h"

int mx_dijkstra_step(int **matrix, int count, int **ptr_ranges, bool **ptr_visited) {
    int *ranges = *ptr_ranges;
    bool *visited = *ptr_visited;
    int temp;

    int min_ind = INT_MAX;
    int min = INT_MAX;

    for (int i = 0; i < count; i++) {
        if (!visited[i] && ranges[i] < min) {
            min = ranges[i];
            min_ind = i;
        }
    }

    if (min_ind != INT_MAX) {
        for (int i = 0; i < count; i++) {
            if (matrix[min_ind][i] > 0) {
                temp = min + matrix[min_ind][i];
                if (temp < ranges[i]) {
                    ranges[i] = temp;
                }
            }
        }

        visited[min_ind] = true;
    }

    return min_ind;
}

int *mx_dijkstra(int **matrix, int count, int index) {
    int *ranges = malloc(sizeof(int) * count);
    bool *visited = malloc(sizeof(bool) * count);

    for (int i = 0; i < count; i++) {
        ranges[i] = INT_MAX;
        visited[i] = false;
    }

    ranges[index] = 0;
    while (mx_dijkstra_step(matrix, count, &ranges, &visited) < INT_MAX);

    free(visited);
    return ranges;
}

