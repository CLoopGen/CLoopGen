#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *dest;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with column-major traversal
    // Access elements by iterating over columns first, then rows (transposed order)
    for (j = 0; j < 3; j++)
        for (i = 0; i < 3; i++) {
            dest->e[i][j].real = dest->e[i][j].imag = 0.;
        }
}
