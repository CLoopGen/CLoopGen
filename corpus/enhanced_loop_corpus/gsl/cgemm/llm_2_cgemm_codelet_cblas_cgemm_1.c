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
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and accessing elements in a more cache-friendly manner
    float *C_ptr = (float *)C;
    const int stride = ldc * 2; // Stride in terms of float elements (complex numbers)
    for (i = 0; i < n1; i++) {
        float *row_base = &C_ptr[i * stride];
        for (j = 0; j < n2; j++) {
            const int idx = 2 * j;
            const float Cij_real = row_base[idx];
            const float Cij_imag = row_base[idx + 1];
            row_base[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
            row_base[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
