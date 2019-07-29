#include "stdio.h"

#include "../kernel/arch/i686/tty.h"
#include "stdlib.h"
#include "string.h"

int putchar(int c) {
    tty_kprint(c);
    return 0;
}

int puts(const char *s) {
    while (*s) {
        putchar(*s++);
    }
    return 0;
}

int vprintf(const char *fmt, va_list arg) {
    int printed = 0;
    char current;
    char buffer[20];

    for (; *fmt; fmt++) {
        current = *fmt;
        if (current == '%') {
            char c;
            char *s;
            int d;
            switch (current = *fmt++) {
            case '%':
                putchar('%');
                printed++;
                continue;
            case 'c':
                c = va_arg(arg, int);
                putchar(c);
                printed++;
                continue;
            case 'd':
            case 'i':
                d = va_arg(arg, int);
                itoa(d, buffer);
                puts(buffer);
                printed += strlen(buffer);
                continue;
            case 's':
                s = va_arg(arg, char *);
                puts(s ? s : "(null)");
                printed += strlen(buffer);
                continue;
            }
        } else {
            putchar(*fmt);
            printed++;
        }
    }
    return printed;
}

int printf(const char *fmt, ...) {
    va_list arg;
    va_start(arg, fmt);
    int printed = vprintf(fmt, arg);
    va_end(arg);
    return printed;
}
