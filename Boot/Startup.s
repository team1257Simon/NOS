.386
extrn _bootUp
.text
bst:
cli
mov ax,cs
mov ds,ax
mov es,ax
mov ss,ax
mov ebp,0x7c00h
mov esp,0x7c00h
sti
call _bootUp
.rept:
jmp .rept
