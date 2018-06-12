#include <string.h>

#include <stddef.h>

size_t strlen(const char *str) {
	size_t s = 0;
	while(str[s]) s++;
	return s;
}
