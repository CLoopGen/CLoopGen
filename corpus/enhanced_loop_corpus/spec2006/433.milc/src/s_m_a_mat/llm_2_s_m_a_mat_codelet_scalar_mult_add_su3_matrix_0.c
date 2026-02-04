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
    // Variant 1: Memory Access Pattern Modification - Interchange loops for row-major to column-major access order
    // This changes the memory access pattern from row-dominant to column-dominant (strided access in original layout)
    for (j = 0; j < 3; j++)
        for (i = 0; i < 3; i++) {
            c->e[i][j].real = a->e[i][j].real + s * b->e[i][j].real;
            c->e[i][j].imag = a->e[i][j].imag + s * b->e[i][j].imag;
        }
}
