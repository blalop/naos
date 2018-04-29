; boot sector
[org 0x7c00]

; kernel offset at 0x1000
KERNEL_OFFSET equ 0x1000
mov [BOOT_DRIVE], dl

; set up the stack
mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call print_string
call load_kernel
call switch_to_pm

jmp $

%include "boot/disk.asm"
%include "boot/gdt.asm"
%include "boot/pm.asm"
%include "boot/print.asm"

[bits  16]
load_kernel:
mov bx, MSG_LOAD_KERNEL
call print_string
mov bx, KERNEL_OFFSET
mov dh, 15
mov dl, [BOOT_DRIVE]
call disk_load
ret

[bits  32]
BEGIN_PM:
call KERNEL_OFFSET
jmp $

; Global  variables
BOOT_DRIVE      db 0
MSG_REAL_MODE   db 10, 13, "Started in 16-bit Real Mode", 0
MSG_LOAD_KERNEL db 10, 13, "Loading kernel into memory...", 0

; Magic
times 510-($-$$) db 0
dw 0xaa55