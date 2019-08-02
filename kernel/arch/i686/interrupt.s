.extern isr_handler

.section .text

isr_common:
  /* 1. Save CPU state */
  pusha /* Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax */
  mov %ds, %ax /* Lower 16-bits of eax = ds */
  push %eax /* save the data segment descriptor */
  mov $0x10, %ax /* kernel data segment descriptor */
  mov %eax, %ds
  mov %eax, %es
  mov %eax, %fs
  mov %eax, %gs
  
  /* 2. Call C handler */
  call isr_handler
  
  /* 3. Restore state */
  pop %eax 
  mov %eax, %ds
  mov %eax, %es
  mov %eax, %fs
  mov %eax, %gs
  popa
  add $0x8, %esp /* Cleans up the pushed error code and pushed ISR number */
  sti
  iret /* pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP */

.global isr0
.type isr0, @function
isr0:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x0       /* Push the interrupt number (0) */
  jmp isr_common    /* Go to our common handler. */

.global isr1
.type isr1, @function
isr1:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x1       /* Push the interrupt number (1) */
  jmp isr_common    /* Go to our common handler. */

.global isr2
.type isr2, @function
isr2:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x2       /* Push the interrupt number (2) */
  jmp isr_common    /* Go to our common handler. */

.global isr3
.type isr3, @function
isr3:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x3       /* Push the interrupt number (3) */
  jmp isr_common    /* Go to our common handler. */

.global isr4
.type isr4, @function
isr4:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x4       /* Push the interrupt number (4) */
  jmp isr_common    /* Go to our common handler. */

.global isr5
.type isr5, @function
isr5:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x5       /* Push the interrupt number (5) */
  jmp isr_common    /* Go to our common handler. */

.global isr6
.type isr6, @function
isr6:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x6       /* Push the interrupt number (6) */
  jmp isr_common    /* Go to our common handler. */

.global isr7
.type isr7, @function
isr7:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x7       /* Push the interrupt number (7) */
  jmp isr_common    /* Go to our common handler. */

.global isr8
.type isr8, @function
isr8:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x8       /* Push the interrupt number (8) */
  jmp isr_common    /* Go to our common handler. */

.global isr9
.type isr9, @function
isr9:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x9       /* Push the interrupt number (9) */
  jmp isr_common    /* Go to our common handler. */

.global isr10
.type isr10, @function
isr10:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0xA       /* Push the interrupt number (10) */
  jmp isr_common    /* Go to our common handler. */

.global isr11
.type isr11, @function
isr11:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0xB       /* Push the interrupt number (11) */
  jmp isr_common    /* Go to our common handler. */

.global isr12
.type isr12, @function
isr12:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0xC       /* Push the interrupt number (12) */
  jmp isr_common    /* Go to our common handler. */

.global isr13
.type isr13, @function
isr13:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0xD       /* Push the interrupt number (13) */
  jmp isr_common    /* Go to our common handler. */

.global isr14
.type isr14, @function
isr14:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0xE       /* Push the interrupt number (14) */
  jmp isr_common    /* Go to our common handler. */

.global isr15
.type isr15, @function
isr15:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0xF       /* Push the interrupt number (15) */
  jmp isr_common    /* Go to our common handler. */

.global isr16
.type isr16, @function
isr16:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x10       /* Push the interrupt number (16) */
  jmp isr_common    /* Go to our common handler. */

.global isr17
.type isr17, @function
isr17:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x11       /* Push the interrupt number (17) */
  jmp isr_common    /* Go to our common handler. */

.global isr18
.type isr18, @function
isr18:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x12       /* Push the interrupt number (18) */
  jmp isr_common    /* Go to our common handler. */

.global isr19
.type isr19, @function
isr19:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x13       /* Push the interrupt number (19) */
  jmp isr_common    /* Go to our common handler. */

.global isr20
.type isr20, @function
isr20:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x14       /* Push the interrupt number (20) */
  jmp isr_common    /* Go to our common handler. */

.global isr21
.type isr21, @function
isr21:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x15       /* Push the interrupt number (21) */
  jmp isr_common    /* Go to our common handler. */

.global isr22
.type isr22, @function
isr22:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x16       /* Push the interrupt number (22) */
  jmp isr_common    /* Go to our common handler. */

.global isr23
.type isr23, @function
isr23:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x17       /* Push the interrupt number (23) */
  jmp isr_common    /* Go to our common handler. */

.global isr24
.type isr24, @function
isr24:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x18       /* Push the interrupt number (24) */
  jmp isr_common    /* Go to our common handler. */

.global isr25
.type isr25, @function
isr25:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x19       /* Push the interrupt number (25) */
  jmp isr_common    /* Go to our common handler. */

.global isr26
.type isr26, @function
isr26:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x1A       /* Push the interrupt number (26) */
  jmp isr_common    /* Go to our common handler. */

.global isr27
.type isr27, @function
isr27:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x1B       /* Push the interrupt number (27) */
  jmp isr_common    /* Go to our common handler. */

.global isr28
.type isr28, @function
isr28:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x1C       /* Push the interrupt number (28) */
  jmp isr_common    /* Go to our common handler. */

.global isr29
.type isr29, @function
isr29:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x1D       /* Push the interrupt number (29) */
  jmp isr_common    /* Go to our common handler. */

.global isr30
.type isr30, @function
isr30:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x1E       /* Push the interrupt number (30) */
  jmp isr_common    /* Go to our common handler. */

.global isr31
.type isr31, @function
isr31:
  cli               /* Disable interrupts */
  push $0x0       /* Push a dummy error code */
  push $0x1F       /* Push the interrupt number (31) */
  jmp isr_common    /* Go to our common handler. */
