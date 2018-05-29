#include <stdio.h>
#include <tty.h>

#if defined(__linux__) || !defined(__i686__)
#error The compiler is not cross-compiler
#endif
 
void kernel_main() {
    clear_screen();
    kprint("\nKernel loaded\n\n");
    puts("Welcome");
    putchar('a');
    puts("AAABBB");
    return;
}
