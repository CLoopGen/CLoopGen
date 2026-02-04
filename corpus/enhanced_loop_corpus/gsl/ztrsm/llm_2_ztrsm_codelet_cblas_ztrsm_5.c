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
    // Variant 1: Consecutive memory access by flattening the 2D index and accessing B in a stride-2 pattern for better spatial locality
    const int total_elements = n1 * n2;
    double *B_ptr = (double *)B;
    for (int idx = 0; idx < total_elements; idx++) {
        const int i = idx / n2;
        const int j = idx % n2;
        const int base_offset = 2 * (ldb * i + j);
        const double Bij_real = B_ptr[base_offset];
        const double Bij_imag = B_ptr[base_offset + 1];
        B_ptr[base_offset]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
        B_ptr[base_offset + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
    }
}
