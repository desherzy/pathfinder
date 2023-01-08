#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
	int i = 0;
    int j = 0;
	
	while (s1[i] != '\0') {
		i++;
	}

    for (j = 0; j < mx_strlen(s2); j++) {
		s1[i + j] = s2[j];
	}

	s1[i + j] = '\0';
	return s1;
}

