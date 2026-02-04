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
    // Variant 1: Consecutive memory access by prefetching and restructuring to access real and imaginary parts in a coalesced manner
    double *C_ptr = (double *)C;
    const int stride = ldc * 2; // Stride in terms of doubles (each complex has 2 doubles)
    for (i = 0; i < n1; i++) {
        int base_offset = 2 * i * ldc;
        for (j = 0; j < n2; j++) {
            int idx = base_offset + 2 * j;
            const double Cij_real = C_ptr[idx];
            const double Cij_imag = C_ptr[idx + 1];
            C_ptr[idx]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[idx + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
