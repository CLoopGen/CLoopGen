#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *a;
extern su3_matrix *b;
extern int i;
extern int j;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (i, j) access, we simulate a strided pattern by accessing every second element
    // in a virtual larger matrix, but still cover all 3x3 elements using modulo arithmetic to stay in bounds.
    sum = 0.0;
    for (i = 0; i < 9; i++) {
        int idx = (i * 7) % 9;  // Stride-like index using prime step and modulo to avoid overlap
        int row = idx / 3;
        int col = idx % 3;
        sum += a->e[row][col].real * b->e[row][col].real + a->e[row][col].imag * b->e[row][col].imag;
    }
}
