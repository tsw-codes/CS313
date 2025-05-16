# Byte-to-ASCII Hex Converter in x86 Assembly

## Description

This program takes an array of 8 bytes stored in memory and converts each byte into its **two-character hexadecimal ASCII representation**, separated by spaces. It then outputs the result to the terminal followed by a newline.

Each byte (e.g., `0x83`) is split into two 4-bit nibbles:
- The **high nibble** (e.g., `8`) and
- The **low nibble** (e.g., `3`)

Each nibble is converted to its corresponding ASCII character (`'8'`, `'3'`) and stored in an output buffer. A space character `' '` is added after each byte, and a newline character is appended at the end.

---

## Files

- `translateToAscii.asm` – The main assembly source file.
- 'subroutine.asm' - extra credit



---

## How to Compile and Run

 Assemble the code

nasm -f elf32 -g -F dwarf -o translateToAscii.o translateToAscii.asm

link the object file 
 ld -m elf_i386 -o translateToAscii translateToAscii.o


## Expected Output
83 6A 88 DE 9A C3 54 9A
