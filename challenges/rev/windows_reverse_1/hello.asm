.386
.MODEL flat

.DATA
flag byte 43h, 44h, 5fh, 58h, 42h, 54h, 52h, 6ah, 66h, 22h, 23h, 78h, 7ch, 61h, 51h, 6ch, 00h

.CODE
public _start
extern _MessageBoxW@16 : PROC
extern _ExitProcess@4 : PROC

_start:

mov eax, offset flag
mov bl, 15h
sub bl, 04h
mov cl, 0
_loop:
xor [eax], bl
inc cl
inc eax
cmp cl, 16
jne _loop


push 0
push 0
push offset flag
push 0
call _MessageBoxW@16

push 0
call _ExitProcess@4



END
