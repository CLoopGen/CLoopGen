#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D index and processing real and imaginary parts together
    const int total_elements = n1 * n2;
    double *C_ptr = (double *)C;
    for (int idx = 0; idx < total_elements; idx++) {
        const int offset = 2 * idx;
        const double C_real = C_ptr[offset];
        const double C_imag = C_ptr[offset + 1];
        C_ptr[offset]     = beta_real * C_real - beta_imag * C_imag;
        C_ptr[offset + 1] = beta_real * C_imag + beta_imag * C_real;
    }
}
