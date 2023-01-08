#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char temp_hex[200];
    int i = 0;

    while (nbr > 0) {
        unsigned long remainder = nbr % 16;
        if (remainder < 10) {
            temp_hex[i] = (48 + remainder);
        }
        else {
            temp_hex[i] = (87 + remainder);
        }

        nbr /= 16;
        i++;
    }

    char *hex = mx_strnew(i);
    for (int j = 0; j < i; j++) {
        hex[j] = temp_hex[i - j - 1];
    }

    return hex;
}

/*
int main() {
    unsigned long a = -12;
    char *hex = mx_nbr_to_hex(a);
    printf("%s\n", hex);
}
*/

