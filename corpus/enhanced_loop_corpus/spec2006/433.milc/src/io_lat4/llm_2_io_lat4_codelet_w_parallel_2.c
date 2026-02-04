#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *lbuf;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 3x3 complex matrix into a linear traversal
    // This improves spatial locality by accessing memory in increasing order without strided jumps
    double *ptr = &lbuf[0].e[0][0].real;
    int total_elements = 4096 * 3 * 3 * 2;  // Each complex has real and imag, 3x3 per matrix
    for (int idx = 0; idx < total_elements; idx += 2) {
        ptr[idx]     = 0.0;  // real part
        ptr[idx + 1] = 0.0;  // imag part
    }
}
