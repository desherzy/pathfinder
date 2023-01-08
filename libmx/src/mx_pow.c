#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (pow > 0) {
		double mult = n;
		for (unsigned int i = 1; i < pow; i++) {
			n *= mult;
		}
	}
	else if (pow == 0) {
		n = 1;
	}
    
	return n;
}

