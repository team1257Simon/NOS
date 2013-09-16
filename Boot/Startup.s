.386
extrn _bootUp
.text
bst:
cli
mov ax,cs
mov ds,ax
mov es,ax
mov ss,ax
mov bp,0x7c00h
mov sp,0x7c00h
sti
call _bootUp
.rept:
jmp .rept
