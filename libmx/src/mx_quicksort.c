#include "../inc/libmx.h"

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) {
        return -1;
    }

    int counter = 0;    

    if (left < right) {
        char *pivot = arr[(left + right) / 2];
        int i = left;
        int j = right;

        while (i < j) {
            while (mx_strlen(arr[i]) < mx_strlen(pivot)) {
                i++;
            }
        
            while (mx_strlen(arr[j]) > mx_strlen(pivot)) {
                j--;
            }

            if (i < j) {
                if (mx_strlen(arr[i]) != mx_strlen(arr[j])) {
                    swap(&arr[i], &arr[j]);
                    counter++;
                }
            }

            i++;
            j--;
        }     
    }
    
    return counter;
}

/*
int main() {
    char *names[] = {"Timmy Turner", "James Maslow", "Oracle", "Siri"};
    //char *names[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};

    printf("counter : %i\n", mx_quicksort(names, 0, 4));
    
    for (int i = 0; i <= 4; i++) {
        printf("%s\n", names[i]);
    }
}
*/

