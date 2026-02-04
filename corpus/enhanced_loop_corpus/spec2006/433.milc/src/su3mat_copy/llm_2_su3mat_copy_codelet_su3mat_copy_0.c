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
    // Variant 1: Strided memory access with column-major traversal
    for (j = 0; j < 3; j++)
        for (i = 0; i < 3; i++) {
            b->e[i][j].real = a->e[i][j].real;
            b->e[i][j].imag = a->e[i][j].imag;
        }
}
