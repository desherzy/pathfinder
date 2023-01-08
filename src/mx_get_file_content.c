#include "../inc/header.h"

int mx_get_file_content(const char* filename, char **content) {
    *content = mx_file_to_str(filename);
    
    if (*content == NULL) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");

        return -1;
    }
    else if (mx_strlen(*content) == 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");

        mx_strdel(content);
        return -2;
    }

    return 0;
}

