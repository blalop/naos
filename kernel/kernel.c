#include <stdio.h>
#include <tty.h>

#if !defined(__i686__)
#error The compiler is not cross-compiler
#endif

void kernel_main(void) {
    clear_screen();
    kprint("\nKernel loaded\n\n");
    puts("Welcome");
    putchar('a');
    puts("AAABBB");
    return;
}
