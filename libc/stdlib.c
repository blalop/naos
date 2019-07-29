#include "stdlib.h"

#include "string.h"

void itoa(int n, char *s) {
    int sign, i = 0;

    if ((sign = n) < 0) {
        n = -n;
    }
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}
