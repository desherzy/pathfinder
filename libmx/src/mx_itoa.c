#include "../inc/libmx.h"

int num_len(int number) {
    int length = 0;

    while (number) {
        number /= 10;
        length++;
    }

    return length;
}

char *mx_itoa(int number) {
    int length = num_len(number);
    char *str = mx_strnew(length);

    if (number == 0) {
        return mx_strcpy(str, "0");
    }

    if (number == -2147483648) {
        return mx_strcpy(str, "-2147483648");
    }

    for (int i = 0; i < length; i++) {
        if (number < 0) {
            str[length] = '-';
            number *= -1;
        }

        str[i] = (number % 10) + '0';
        number /= 10;
    }

    mx_str_reverse(str);
    return str;
}

