<<<<<<< HEAD
SECTION .text

=======

SECTION .text
>>>>>>> branch 'master' of https://github.com/team1257Simon/NOS.git
bst:
cli
<<<<<<< HEAD
mov ax, 0x2401
int 0x15
=======
push ax
mov al,0xdd
out 0x64,al
pop ax
>>>>>>> branch 'master' of https://github.com/team1257Simon/NOS.git
mov ax,cs
mov ds,ax
mov es,ax
mov ss,ax
mov ebp,0x7c00
mov esp,0x7c00
sti
<<<<<<< HEAD
jmp 0x1000000
=======
jmp 0x1000
>>>>>>> branch 'master' of https://github.com/team1257Simon/NOS.git
.rept:
jmp .rept
db 0x55
db 0xAA
