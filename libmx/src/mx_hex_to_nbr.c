#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) {
        return 0;
    }

    int lenght = 0;
    while (hex[lenght] != '\0') {
        lenght++;
    }

    unsigned long result = 0;
    unsigned long decimal = 1;

    for (int i = lenght - 1; i >= 0; i--) {
        if (hex[i] >= 48 && hex[i] <= 57) { //is digit
            result += (hex[i] - 48) * decimal;
            decimal *= 16;
        }
        else if ((hex[i] >= 65 && hex[i] <= 90) || (hex[i] >= 97 && hex[i] <= 122)) { //is alpha
            if (hex[i] >= 97 && hex[i] <= 122) { //lower
                result += (hex[i] - 87) * decimal;
                decimal *= 16;
            }
            else if (hex[i] >= 65 && hex[i] <= 90) { //upper
                result += (hex[i] - 55) * decimal;
                decimal *= 16;
            }
        }
    }

    return result;
}

