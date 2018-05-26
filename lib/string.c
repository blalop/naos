#include "string.h"

void *memcpy(void *s1, void *s2, size_t n) {
	uint8_t *ss1 = (uint8_t*) s1;
	uint8_t *ss2 = (uint8_t*) s2;
    for (size_t i = 0; i < n; i++) {
        ss1[i] = ss2[i];
    }
	return ss1;
}

size_t strlen(const char *str) {
	size_t s = 0;
	while(str[s]) s++;
	return s;
}

