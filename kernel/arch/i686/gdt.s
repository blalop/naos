.section .text
.global gdt_flush      /* Allows the C code to call gdt_flush() */
.type gdt_flush, @function

gdt_flush:
   mov 0x4(%esp), %eax /* Get the pointer to the GDT, passed as a parameter. */
   lgdt (%eax)         /* Load the new GDT pointer */

   mov $0x10, %ax      /* 0x10 is the offset in the GDT to our data segment */
   mov %eax, %ds       /* Load all data segment selectors */
   mov %eax, %es
   mov %eax, %fs
   mov %eax, %gs
   mov %eax, %ss
   jmp $0x08,$.flush   /* 0x08 is the offset to our code segment: Far jump! */
.flush:
   ret
