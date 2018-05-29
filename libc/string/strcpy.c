#include <string.h>

#include <stddef.h>

char *strcpy(char *destination, const char *source) {
    size_t i = 0;
    while ((destination[i] = source[i]) != '\0') i++;
	return destination;
}