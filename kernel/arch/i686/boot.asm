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

; 1st flags: present, privilege(2), descript type
; type flags: code, conforming, readable, accessed
; 2nd  flags: granularity, 32-bit  default, 64-bit  seg, AVL
gdt_start:
gdt_null: ; null descriptor
dd 0x0 
dd 0x0
gdt_code: ; code segment descriptor
; base=0x0, limit=0xfffff
dw 0xffff    ; Limit 0:15
dw 0x0       ; Base 0:15
db 0x0       ; Base 16:23
db 10011010b ; 1st flags, type flags
db 11001111b ; 2nd flags , Limit 16:19
db 0x0       ; Base 24:31
gdt_data: ; data segment descriptor
; same as code segment except for the type flags:
dw 0xffff    ; Limit 0:15
dw 0x0       ; Base 0:15
db 0x0       ; Base 16:23
db 10010010b ; 1st flags, type flags
db 11001111b ; 2nd flags, Limit 16:19
db 0x0       ; Base 24:31
gdt_end:
gdt_descriptor:
dw gdt_end - gdt_start - 1 ; Size of GDT
dd gdt_start               ; Start address of GDT



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