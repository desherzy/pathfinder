#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (arr != NULL && delim != NULL) {
        for (int i = 0; arr[i] != NULL; i++) {
            mx_printstr(arr[i]);

            if (arr[i + 1]) {
                mx_printstr(delim);
            }
        }
        write(1, "\n", 1);
    }
}

/*
int main() {
    char *str[] = {"Timmy Turner", "James Maslow", "Oracle", "Siri"};
    mx_print_strarr(str, " ");
}
*/

