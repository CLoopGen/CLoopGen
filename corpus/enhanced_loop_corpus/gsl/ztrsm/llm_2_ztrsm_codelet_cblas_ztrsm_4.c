#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D index and accessing B in row-major order
    const int total_elements = n1 * n2;
    double *B_ptr = (double *)B;
    for (i = 0; i < total_elements; i++) {
        const double Bij_real = B_ptr[2 * i];
        const double Bij_imag = B_ptr[2 * i + 1];
        B_ptr[2 * i] = alpha_real * Bij_real - alpha_imag * Bij_imag;
        B_ptr[2 * i + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
    }
}
