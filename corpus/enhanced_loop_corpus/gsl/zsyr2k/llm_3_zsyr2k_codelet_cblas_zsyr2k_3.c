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
    // Variant 2: Strided memory access pattern using a fixed stride for traversing column-major like structure with step-based indexing
    double *C_base = (double *)C;
    const int stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            const int index = i + j * ldc; // Transposed index to change access pattern
            const double Cij_real = C_base[2 * index];
            const double Cij_imag = C_base[2 * index + 1];
            C_base[2 * index]       = beta_real * Cij_real - beta_imag * Cij_imag;
            C_base[2 * index + 1]   = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
