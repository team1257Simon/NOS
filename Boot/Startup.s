.386
extrn _bootUp
.text
bst:
mov ax,cs
mov ds,ax
mov es,ax
mov ss,ax
mov bp,0x7c00h
mov sp,0x7c00h
call _bootUp
.rept:
jmp .rept
