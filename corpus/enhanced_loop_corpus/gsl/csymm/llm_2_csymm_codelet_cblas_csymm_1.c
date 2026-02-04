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
    // Variant 1: Consecutive memory access by flattening the 2D index space
    // We traverse the matrix in row-major order, but precompute base pointers for better locality
    float *C_ptr = (float *)C;
    const int stride = ldc * 2; // Stride in float units per row
    for (i = 0; i < n1; i++) {
        int base_idx = i * stride;
        for (j = 0; j < n2; j++) {
            int idx = base_idx + j * 2; // Precomputed index for real part
            const float Cij_real = C_ptr[idx];
            const float Cij_imag = C_ptr[idx + 1];
            C_ptr[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
