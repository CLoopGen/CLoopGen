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
    const int stride = ldc * 2; // Stride in terms of doubles (each complex number has 2 components)
    for (i = 0; i < N; i++) {
        int base_index = stride * i + 2 * i; // Starting at diagonal element (i,i): 2*(ldc*i + i)
        for (j = i; j < N; j++) {
            const double Cij_real = C_ptr[base_index];
            const double Cij_imag = C_ptr[base_index + 1];
            C_ptr[base_index]     = beta_real * Cij_real - beta_imag * Cij_imag;
            C_ptr[base_index + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
            base_index += 2; // Move to next column in same row (consecutive complex storage)
        }
    }
}
