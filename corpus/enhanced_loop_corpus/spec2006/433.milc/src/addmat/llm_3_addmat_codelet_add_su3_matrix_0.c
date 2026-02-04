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
extern su3_matrix *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — traverse column-major (j then i) instead of row-major
    // This creates a non-unit stride in how the matrix elements are accessed, affecting cache behavior
    for (j = 0; j < 3; j++)
        for (i = 0; i < 3; i++) {
            (c->e[i][j]).real = (a->e[i][j]).real + (b->e[i][j]).real;
            (c->e[i][j]).imag = (a->e[i][j]).imag + (b->e[i][j]).imag;
        }
}
