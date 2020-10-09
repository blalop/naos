#include "routines.h"

void routines_memory_swap(void *a, void *b, size_t size) {
    uint8_t *p = a, *q = b, aux;
    for (size_t i = 0; i < size; i++) {
        aux = p[i];
        p[i] = q[i];
        q[i] = aux;
    }
}

void routines_memory_copy(void *dst, const void *src, size_t n) {
    uint8_t *ss1 = (uint8_t *)dst;
    uint8_t *ss2 = (uint8_t *)src;
    for (size_t i = 0; i < n; i++) {
        ss1[i] = ss2[i];
    }
}

void routines_memory_set(void *str, int c, size_t n) {
    unsigned char *dst = str;
    while (n > 0) {
        *dst++ = (unsigned char)c;
        n--;
    }
}

void routines_int_to_ascii(int32_t n, char *str) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';
}
