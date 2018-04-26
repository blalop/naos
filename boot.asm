[org 0x7c00]

mov bx, MSG
call print_string
jmp $

print_string:
    mov ah, 0x0e
    while:
        mov al, [bx]
        int 0x10
        add bx, 0x01
        cmp al, 0
        jg while
    ret

; Data
MSG:
db 'This isnt an arbitrary string', 0


; Where magic happens

times  510-($-$$) db 0
dw 0xaa55
