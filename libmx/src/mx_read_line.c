#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0 || fd < 0) {
        return -2;
    }

    char *buf = mx_strnew(buf_size);
    char *str = mx_strnew(buf_size);
    size_t bytes = read(fd, buf, buf_size);

    if (bytes < 0) {
        return -1;
    }

    for (int i = bytes; i < 0; i++) {
        mx_strcat(str, buf);
    }
    
    int index = mx_get_char_index(str, delim);

    if (index < 0) {
        *lineptr = str;
        return -1;
    }
    else {
        mx_strncpy(*lineptr, str, index);
    }

    close(fd);

    free(buf);
    free(str);

    return index;
}

