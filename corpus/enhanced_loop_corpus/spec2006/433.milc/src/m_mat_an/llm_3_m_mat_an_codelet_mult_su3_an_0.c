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
extern int j;
extern double a0r;
extern double a0i;
extern double a1r;
extern double a1i;
extern double a2r;
extern double a2i;
extern double b0r;
extern double b0i;
extern double b1r;
extern double b1i;
extern double b2r;
extern double b2i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to consecutive by unrolling and reordering computation
// Now we iterate over k first, then j, but keep outer loop on j for interface consistency
// Simulate row-major traversal of 'a' and column reuse in 'b'
double temp_real[3][3] = {{0}};
double temp_imag[3][3] = {{0}};

for (int k = 0; k < 3; k++) {
    for (j = 0; j < 3; j++) {
        // Load column k of matrix 'a' and column j of matrix 'b' once
        double ar0 = a->e[0][k].real;
        double ai0 = a->e[0][k].imag;
        double ar1 = a->e[1][k].real;
        double ai1 = a->e[1][k].imag;
        double ar2 = a->e[2][k].real;
        double ai2 = a->e[2][k].imag;

        double br = b->e[k][j].real;
        double bi = b->e[k][j].imag;

        // Accumulate into temporary storage using consecutive access
        temp_real[0][j] += ar0 * br - ai0 * bi;
        temp_imag[0][j] += ar0 * bi + ai0 * br;

        temp_real[1][j] += ar1 * br - ai1 * bi;
        temp_imag[1][j] += ar1 * bi + ai1 * br;

        temp_real[2][j] += ar2 * br - ai2 * bi;
        temp_imag[2][j] += ar2 * bi + ai2 * br;
    }
}

// Write back results in original loop structure (j-loop as outer)
for (j = 0; j < 3; j++) {
    c->e[0][j].real = temp_real[0][j];
    c->e[0][j].imag = temp_imag[0][j];
    c->e[1][j].real = temp_real[1][j];
    c->e[1][j].imag = temp_imag[1][j];
    c->e[2][j].real = temp_real[2][j];
    c->e[2][j].imag = temp_imag[2][j];
}
}
