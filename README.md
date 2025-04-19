Name: Oluwatomisin Sapara-williams 
Class : CMSC 313 Mon/Wed 2:30-3:45
Purpose: The purpose of this programs that are written in C++  and C is to implement a matrix expression that computes 
D =  A + (3 * B x C^t)
Where:
- `A` is a 2×2 matrix
- `B` is a 2×3 matrix
- `C` is a 2×3 matrix, and `Cᵀ` is its transpose (3×2)
- `D` is the resulting 2×2 matrix after computing the expression

The program demonstrates:
- Matrix scaling (multiplying `B` by a scalar value `3`)
- Matrix transposition (`Cᵀ`)
- Matrix multiplication between a 2×3 and a 3×2 matrix
- Element-wise matrix addition between `A` and the result of the product
- Matrix printing to the console

### 💻 Technologies Used
- Language: C (C99 Standard) or C++
- Compiler: GCC (x86 architecture)

### 🔧 Compilation Instructions

#### For C version:
```bash
gcc -std=c99 -Wall -o matrix matrix.c
./matrix

for C++:
g++ -o matrix matrix.cpp
