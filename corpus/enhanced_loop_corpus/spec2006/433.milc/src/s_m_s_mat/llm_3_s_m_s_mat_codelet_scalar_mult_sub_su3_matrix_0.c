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
extern double s;
extern su3_matrix *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Linearized Index with Consecutive Memory Access Pattern
    // Treating the 3x3 matrix as a linear array of 9 complex elements
    int idx;
    for (idx = 0; idx < 9; idx++) {
        int row = idx / 3;
        int col = idx % 3;
        c->e[row][col].real = a->e[row][col].real - s * b->e[row][col].real;
        c->e[row][col].imag = a->e[row][col].imag - s * b->e[row][col].imag;
    }
}
