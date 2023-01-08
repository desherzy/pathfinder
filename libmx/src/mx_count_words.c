#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int counter = 0;
    int pass = 1;
    
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == c) {
            pass = 1;
        }
        else if (pass == 1) {
            pass = 0;
            counter++;
        }
    }

    return counter;
}

/*
int main() {
    char str[] = "Mugiwara Luffy * used 5th Gear 0_0 ";

    printf("counter of words : %i\n", mx_count_words(str, '*'));
}
*/

