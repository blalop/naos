#include "string.h"

#include <stdint.h>

void *memcpy(void *dst, const void *src, size_t n) {
    uint8_t *ss1 = (uint8_t *)dst;
    uint8_t *ss2 = (uint8_t *)src;
    for (size_t i = 0; i < n; i++) {
        ss1[i] = ss2[i];
    }
    return ss1;
}

char *strcpy(char *dst, const char *src) {
    size_t i = 0;
    while ((dst[i] = src[i]) != '\0')
        i++;
    return dst;
}
size_t strlen(const char *str) {
    size_t s = 0;
    while (str[s]) {
        s++;
    }
    return s;
}
