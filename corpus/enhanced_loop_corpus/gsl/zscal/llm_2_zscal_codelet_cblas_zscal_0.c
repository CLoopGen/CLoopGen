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
    // Variant 1: Consecutive memory access with pointer arithmetic
    double *x_ptr = (double *)X;
    for (i = 0; i < N; i++) {
        const int offset = 2 * ix;
        const double x_real = x_ptr[offset];
        const double x_imag = x_ptr[offset + 1];
        x_ptr[offset]     = x_real * alpha_real - x_imag * alpha_imag;
        x_ptr[offset + 1] = x_real * alpha_imag + x_imag * alpha_real;
        ix += incX;
    }
}
