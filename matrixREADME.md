Name: Oluwatomisin Sapara-williams 
Class : CMSC 313 Mon/Wed 2:30-3:45
# Matrix Expression Evaluator

## PURPOSE OF SOFTWARE:
This program computes a matrix expression of the form:
D = A + (3 * B + C^T)

It demonstrates basic matrix operations including scalar multiplication, transposition, matrix multiplication, and matrix addition. 

---

## FILES:
- `matrix.c` and `matrix.cpp`: The main source file containing the entire logic for initializing matrices, performing matrix operations, and printing the final result.
 `README.md`: This documentation file.


---

## BUILD INSTRUCTIONS:

### For C (C99):
```bash
gcc -std=c99 -Wall -o matrix matrix.c
./matrix

for C ++:
g++ -o matrix matrix.cpp
---

Expected output :
D = A + (3 * B × Cᵀ):
90  70
200 153


