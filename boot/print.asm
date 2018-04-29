; print functions

; 16-bit
[bits 16]
; prints a null-terminated string pointed to by BX
print_string:
mov ah, 0x0e
print_string_loop:
mov al, [bx]
int 0x10
add bx, 0x01
cmp al, 0
jg print_string_loop
ret

; 32-bit / PM
[bits 32]
VIDEO_MEMORY equ 0xb8000 ; start address
WHITE_ON_BLACK equ 0x0f ; ASCII attributes
; prints a null-terminated string pointed to by EDX
print_string_pm:
pusha
mov edx, VIDEO_MEMORY
print_string_pm_loop:
mov al, [ebx]
mov ah, WHITE_ON_BLACK
cmp al, 0
je print_string_pm_ret
mov [edx], ax
; character cell
add ebx, 1
add edx, 2
jmp print_string_pm_loop
print_string_pm_ret:
popa
ret
