#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and accessing elements in a more cache-friendly manner
    double *C_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        const int base_offset_i = 2 * ldc * i;
        for (j = 0; j <= i; j++) {
            const int offset = base_offset_i + 2 * j;
            const double Cij_real = C_ptr[offset];
            const double Cij_imag = C_ptr[offset + 1];
            C_ptr[offset]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[offset + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
