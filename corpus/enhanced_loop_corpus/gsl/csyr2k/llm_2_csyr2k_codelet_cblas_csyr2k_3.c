#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and accessing elements sequentially
    float *C_ptr = (float *)C;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            const ptrdiff_t idx = 2 * (ldc * i + j);
            const float Cij_real = C_ptr[idx];
            const float Cij_imag = C_ptr[idx + 1];
            C_ptr[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
