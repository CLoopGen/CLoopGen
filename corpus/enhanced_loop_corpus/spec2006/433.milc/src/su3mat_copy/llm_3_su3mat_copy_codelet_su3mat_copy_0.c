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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Linearized index with consecutive memory access using pointer arithmetic
    complex *ap = &a->e[0][0];
    complex *bp = &b->e[0][0];
    for (int idx = 0; idx < 9; idx++) {
        bp[idx].real = ap[idx].real;
        bp[idx].imag = ap[idx].imag;
    }
}
