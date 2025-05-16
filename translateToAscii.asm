section .data
inputBuf:db  0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A 
size: equ 8 ;how many bytes to translate

section .bss
outputBuf: resb 80 ;space to hold ASCII output

section .text
global _start

;setup 

_start:
    mov esi, inputBuf  ;pointer to input buffer
    mov edi, outputBuf ;pointer to output buffer
    mov ecx, size     ;counter

loop:
    cmp ecx, 0
    je exit          ;exit when all bytes are processed

    mov al, [esi]    ;getting next byte from input buffer
    inc esi 

    ;isolating and translating first 4 bits 
    mov ah, al       ;copy full bytes to ah
    shr al, 4        ;shift right 

    cmp al, 9
    jbe .higher_num  ;if 0-9, convert ASCII digit
    add al, 'A' -10  ; else convert to ASCII letter A-F
    jmp .store_high

.higher_num:
    add al, '0'     ; convert 0-9 to ASCII

.store_high:          
    mov [edi], al   ;storing ASCII char in output buffer 
    inc edi
    ; isolating and translate low, the last 4 bits
    mov al, ah
    and al, 0x0F    ;to get only low bits 

    cmp al, 9
    jbe .lower_num   ; if 0-9, convert to ASCII digit
    add al, 'A' -10  ; convert 10-15 to ASCII letter A-F
    jmp .store_low

.lower_num:
    add al, '0'

.store_low:
    mov [edi], al
    inc edi

    mov byte[edi], ' ' ;add a space between each byte
    inc edi

    dec ecx
    jmp loop

exit:
    ; Replace last space with newline before printing 
    dec edi
    mov byte [edi], 0x0A
    inc edi

    mov eax, 4         ;syscall
    mov ebx, 1
    mov ecx, outputBuf  ;pointer to message 
    sub edi, outputBuf  ;length of output
    mov edx, edi
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80




