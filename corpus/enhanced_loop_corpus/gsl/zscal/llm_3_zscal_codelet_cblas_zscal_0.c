#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern int i;
extern int ix;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with precomputed index increments
    double *base = (double *)X;
    int current_index = 0; // Local index tracking to avoid repeated multiplication
    int stride = 2 * incX; // Stride in terms of double elements

    for (i = 0; i < N; i++) {
        const double x_real = base[current_index];
        const double x_imag = base[current_index + 1];
        base[current_index]     = x_real * alpha_real - x_imag * alpha_imag;
        base[current_index + 1] = x_real * alpha_imag + x_imag * alpha_real;
        current_index += stride;
    }
}
