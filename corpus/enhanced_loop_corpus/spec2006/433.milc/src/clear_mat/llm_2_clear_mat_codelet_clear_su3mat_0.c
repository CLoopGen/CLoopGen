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
    // Variant 1: Consecutive memory access using linear indexing
    // Flatten the 3x3 matrix into sequential accesses to improve spatial locality
    double *ptr = &dest->e[0][0].real;
    for (int idx = 0; idx < 18; idx += 2) {
        ptr[idx]     = 0.0; // real part
        ptr[idx + 1] = 0.0; // imag part
    }
}
