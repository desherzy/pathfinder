#include "../inc/header.h"

void mx_del_bridge(t_bridge **bridge) {
    mx_strdel(&(*bridge)->start);
    mx_strdel(&(*bridge)->finish);
    free(*bridge);
    *bridge = NULL;
}

