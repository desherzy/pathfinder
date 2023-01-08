#include "../inc/header.h"

int main(int argc, char *argv[]) {
	int error;

	if ((error = mx_check_usage_error(argc)) < 0) {
		return error;
	}

	char *content = NULL;
	if ((error = mx_get_file_content(argv[1], &content)) < 0) {
		return error;
	}

	char **verticles = NULL;
	t_bridge **bridges = NULL;

	int count = 0;

	error = mx_read_bridges(content, &bridges, &verticles, &count);
	mx_strdel(&content);
	
	if (error < 0) {
		return error;
	}

	int **matrix = mx_create_adj_matrix(verticles, count, bridges);

	for (int i = 0; i < count; i++) {
		int *ranges = mx_dijkstra(matrix, count, i);
		t_list *paths = mx_get_paths(i, verticles, matrix, ranges, count);

		free(ranges);
		ranges = NULL;

		for (t_list *path = paths; path != NULL;) {
			mx_print_path(path->data, verticles);

			for (t_list *j = path->data; j != NULL; mx_pop_front(&j));

			t_list *temp = path;
			path = path->next;

			free(temp);
		}
	}

	for (int i = 0; i < count; i++) {
		free(matrix[i]);
	}

	free(matrix);
	matrix = NULL;

	mx_del_strarr(&verticles);

	for (int i = 0; bridges[i] != NULL; i++) {
		mx_del_bridge(&bridges[i]);
	}

	free(bridges);
	bridges = NULL;
}

