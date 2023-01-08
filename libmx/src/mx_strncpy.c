#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	int index = 0;

	while (index != len) {
		dst[index] = src[index];
		index++;
	}
	return (char *)dst;
}

