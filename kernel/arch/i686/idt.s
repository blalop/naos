.section .text
.global idt_flush      /* Allows the C code to call idt_flush() */
.type idt_flush, @function

idt_flush:
   mov 0x4(%esp), %eax /* Get the pointer to the IDT, passed as a parameter */
   lidt (%eax)         /* Load the IDT pointer */
   ret
