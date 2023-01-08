#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (!*arr) {
        return -1;
    }

    int min = 0;
    int mid;
    int max = size - 1;

    while (min <= max) {
        mid = (min + max) / 2;
        if (mx_strcmp(arr[mid], s) > 0) {
            max = mid - 1;
        }
        else if (mx_strcmp(arr[mid], s) < 0) {
            min = mid + 1;
        }
        else {
            return mid;
        }

        (*count)++;
    }
    *count = 0;
    return -1;
}

/*
int main() {
    char *str[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    int count = 0;
    printf("return : %i, count : %i\n", mx_binary_search(str, 6, "aBc", &count), count);

}
*/

