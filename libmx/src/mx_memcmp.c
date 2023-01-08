#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    size_t i = 0;
    const unsigned char *str1 = s1;
    const unsigned char *str2 = s2;

    while (i < n && str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0') {
            return 0;
        }

        i++;
    }

    return str1[i] - str2[i];
}

/*
int main() {
    char str1[] = "abcdifg";
    char str2[] = "ABCDIFG";

    printf("diff is : %i\n", mx_memcmp(str1, str2, 8));
}
*/

