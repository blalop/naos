#include "math.h"

int abs(int n) { return n > 0 ? n : -n; }

long labs(long n) { return n > 0 ? n : -n; }

div_t div(int x, int y) {
    div_t div = {.quot = x / y, .rem = x % y};
    return div;
}

ldiv_t ldiv(long x, long y) {
    ldiv_t ldiv = {.quot = x / y, .rem = x % y};
    return ldiv;
}
