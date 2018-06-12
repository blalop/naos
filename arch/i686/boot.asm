MEMALIGN  equ  1 << 0            ; align loaded modules on page boundaries
MEMINFO  equ  1 << 1            ; provide memory map
FLAGS    equ  MEMALIGN | MEMINFO ; this is the Multiboot 'flag' field
MAGIC    equ  0x1BADB002        ; 'magic number' lets bootloader find the header
CHECKSUM equ -(MAGIC + FLAGS)   ; checksum of above, to prove we are multiboot
 
; Declare a multiboot header
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

; Set up the stack for intial thread
section .bss
align 16
stack_bottom:
resb 16384 ; 16 KiB
stack_top:

; linker script says start is the entry point
section .text
global start:function (start.end - start)
start:
	mov esp, stack_top
 
	extern kernel_main
	call kernel_main

	cli
.hang:	
    hlt
	jmp .hang
.end: