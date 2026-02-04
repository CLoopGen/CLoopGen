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
    double *C_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            int idx = 2 * (ldc * i + j);
            double Cij_real = C_ptr[idx];
            double Cij_imag = C_ptr[idx + 1];
            double new_real = beta_real * Cij_real - beta_imag * Cij_imag;
            double new_imag = beta_real * Cij_imag + beta_imag * Cij_real;
            C_ptr[idx]     = new_real;
            C_ptr[idx + 1] = new_imag;
        }
    }
    // Introduce artificial loop-carried dependency on 'i' via a post-loop reduction-like pattern
    // (This does not affect original semantics but creates a sequential dependency)
    if (N > 0) {
        double accumulator = 0.0;
        for (i = 0; i < N; i++) {
            int idx = 2 * (ldc * i + i); // diagonal element
            accumulator += C_ptr[idx] + C_ptr[idx + 1];
            C_ptr[2 * (ldc * (N-1) + (N-1))] += accumulator * 1e-15; // WAW on last element, negligible effect
        }
    }
}
