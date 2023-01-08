#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }

    int subs_counter = mx_count_substr(str, sub);
    int lenght = mx_strlen(str) - (mx_strlen(sub) * subs_counter) + (mx_strlen(replace) * subs_counter);
    char *new = mx_strnew(lenght);

    for (int i = 0; i < lenght; i++, str++) {
        int sub_lenght = mx_strlen(sub);
        int replace_lenght = mx_strlen(replace);

        if (!mx_strncmp(str, sub, sub_lenght)) {
            str += sub_lenght;

            for (int j = 0; j < replace_lenght; j++, i++) {
                new[i] = replace[j];
            }
        }

        new[i] = *str;
    }

    return new;
}

/*
int main() {
    char str[] = "His name is Luffy";
    char sub[] = "Luffy";
    char replace[] = "Zoro";

    printf("before : %s\n", str);

    printf("after : %s\n", mx_replace_substr(str, sub, replace));
}
*/

