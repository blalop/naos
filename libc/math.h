#ifndef _MATH_H
#define _MATH_H 1

int abs(int n);
long labs(long n);
long long llabs(long long n);

typedef struct div_ {
    int quot;
    int rem;
} div_t;

typedef struct ldiv_ {
    long quot;
    long rem;
} ldiv_t;

div_t div(int x, int y);
ldiv_t ldiv(long x, long y);

#endif // _MATH_H
