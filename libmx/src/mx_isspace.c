#include "../inc/libmx.h"

bool mx_isspace(char c) {
	if (c >= 30 && c <= 32) {
		return 1;
	}
	else if (c == '\t' 
		|| c == '\n' 
		|| c == '\f' 
		|| c == '\v' 
		|| c == '\r') {
		return 1;
	}
	else {
		return 0;
	}
}

