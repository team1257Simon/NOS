
SECTION .text
bst:
cli
push ax
mov al,0xdd
out 0x64,al
pop ax
mov ax,cs
mov ds,ax
mov es,ax
mov ss,ax
mov ebp,0x7c00
mov esp,0x7c00
sti
jmp 0x1000
.rept:
jmp .rept
