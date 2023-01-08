#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len > 0 && little_len > 0 && big_len >= little_len) {
        unsigned char *s1 = (unsigned char *)big;
        unsigned char *s2 = (unsigned char *)little;

        while (*s1 != '\0') {
            if (mx_memcmp(s1, s2, little_len - 1) == 0) {
                return s1;
            }

            s1++;
        }
    }

    return NULL;
}

/*
int main() {
    char big[] = "ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE TEN";
    size_t big_lenght = mx_strlen(big);

    char little[] = "SIX";
    size_t little_lenght = mx_strlen(little);

    printf("memmem : %s\n", mx_memmem(big, big_lenght, little, little_lenght));
}
*/

