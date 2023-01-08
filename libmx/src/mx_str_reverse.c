#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
	int lenght = mx_strlen(s);
    int i = 0;

	while (i < lenght / 2) {
		mx_swap_char(&s[i], &s[lenght - 1 - i]);
		i++;
	}
}

/*
int main() {
    char str[] = "Hi mindset";
    mx_str_reverse(str);
    printf("reverse : %s\n", str);
}
*/

