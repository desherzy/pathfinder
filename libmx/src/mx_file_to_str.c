#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int length = 0;
    char c;
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        return NULL;
    }

    while (read(fd, &c, 1) != 0) {
        length++;
    }
    
    close(fd);

    char *str = mx_strnew(length);
    
    fd = open(file, O_RDONLY);
    read(fd, str, length);
    str[length] = '\0';
    
    close(fd);
    return str;
}

