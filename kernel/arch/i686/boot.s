/* Multiboot header constants */
.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

/* Declare a multiboot header that marks the program as a kernel */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* It's up to us to provide a stack. Must be 16-byte aligned */
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

/* The linker script specifies start as the entry point to the kernel */
.section .text
.global start
.type start, @function
start:
    /* x86 32-bit protected mode */

    /* Set up a stack */
    mov $stack_top, %esp

    /* Initialization point: FP, GDT, instruction set, paging, C++ */

    /* Enter the high-level kernel. We're not coming back. */
    call kmain

.size start, . - start
