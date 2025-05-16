# Byte-to-ASCII Hex Converter in x86 Assembly

## Description

This program takes an array of 8 bytes stored in memory and converts each byte into its **two-character hexadecimal ASCII representation**, separated by spaces. It then outputs the result to the terminal followed by a newline.

Each byte (e.g., `0x83`) is split into two 4-bit nibbles:
- The **high nibble** (e.g., `8`) and
- The **low nibble** (e.g., `3`)

Each nibble is converted to its corresponding ASCII character (`'8'`, `'3'`) and stored in an output buffer. A space character `' '` is added after each byte, and a newline character is appended at the end.

This version of the program **does not use subroutines**. All logic is inline within the main loop.

---

## Files

- `printData.asm` – The main assembly source file.
- *(You must rename your `.asm` file to match or adjust compilation instructions accordingly.)*

---

## Requirements

- NASM (Netwide Assembler)
- Linux OS with 32-bit support
- GNU `ld` linker

If you're using a 64-bit Linux system, you may need to install 32-bit libraries and enable 32-bit support.

---

## How to Compile and Run

### Step 1: Assemble the code

nasm -f elf32 translateToAscii.asm -o translateToAscii.o

## Expected Output
83 6A 88 DE 9A C3 54 9A
