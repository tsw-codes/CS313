section .data
inputBuf:db  0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A 
size: equ 8 ;how many bytes to translate

section .bss
outputBuf: resb 80 ;space to hold ASCII output

section .text
global _start

;setup 

_start:
    mov esi, inputBuf  ;read data from inputBuf
    mov edi, outputBuf ;copy to outputBuf
    mov ecx, size     ;number of bytes 

loop:
    cmp ecx, 0
    je exit 

    mov al, [esi]
    inc esi 

    mov ah, al
    shr al, 4
    call char_translate
    mov[edi], al
    inc edi

    mov al, ah
    and al, 0x0F
    call char_translate
    mov [edi], al
    inc edi

    mov byte[edi], ' '
    inc edi

    dec ecx
    jmp loop

    char_translate:
        cmp al, 9
        jbe .num
        add al, 'A' - 10
        ret 
    .num: 
        add al, '0'
        ret
    exit:
        dec edi
        mov byte[edi], 0x0A
        inc edi

        mov eax, 4
        mov ebx, 1
        mov ecx, outputBuf
        mov edi, outputBuf
        mov edx, edi
        int 0X80

        mov eax, 1
        xor ebx, ebx
        int 0x80