; boot sector
[org 0x7c00]

mov [BOOT_DRIVE], dl

; set up the stack
mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call print_string
call load_kernel
call switch_to_pm
call KERNEL_OFFSET


load_kernel:
mov bx, MSG_LOAD_KERNEL
call print_string
mov bx, KERNEL_OFFSET
mov dh, 15
mov dl, [BOOT_DRIVE]
call disk_load
ret

switch_to_pm:
cli
lgdt [gdt_descriptor]
mov eax, cr0
or eax, 0x1
mov cr0, eax
jmp CODE_SEG:init_pm ; Clear pipeline
ret 

[bits  32]
init_pm:
mov ax, DATA_SEG
mov ds, ax
mov ss, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ebp, 0x90000
mov esp, ebp
ret


; Includes
%include "boot/disk.asm"
%include "boot/gdt.asm"
%include "boot/print.asm"

; Global  variables
KERNEL_OFFSET equ 0x1000
BOOT_DRIVE      db 0
MSG_REAL_MODE   db 10, 13, "Started in 16-bit Real Mode", 0
MSG_LOAD_KERNEL db 10, 13, "Loading kernel into memory...", 0

; Magic
times 510-($-$$) db 0
dw 0xaa55