#include "../inc/libmx.h"

int mx_atoi(const char *str) {
	int number = 0;
	bool negative = false;
	
	while (mx_isspace(*str)) {
		str++;
	}
	
	if (*str == '+' || *str == '-') {
		if (*str++ == '-') {
			negative = !negative;
		}
	}

	while (*str != '\0') {
		if (mx_isspace(*str)) {
			str++;
			continue;
		}

		if (*str < '0' || *str > '9') {
			return 0;
		}
		
		number *= 10;
		number += *str - '0';
		str++;
	}

	if (negative) {
		number *= -1;
	}
		
	return number;
}

