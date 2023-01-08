#include "../inc/header.h"

int mx_check_usage_error(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return -1;
    }
    
    return 0;
}

