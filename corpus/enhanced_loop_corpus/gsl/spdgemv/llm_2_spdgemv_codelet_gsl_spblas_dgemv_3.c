#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern size_t j;
extern size_t incX;
extern size_t incY;
extern size_t lenY;
extern double *X;
extern double *Y;
extern double *Ad;
extern int *Ap;
extern int *Ai;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to consecutive by unrolling and reordering computation
    // We assume that the sparsity pattern allows for some degree of vectorization or coalesced access.
    // Here, we iterate over the non-zero elements directly and update Y in a strided but more cache-friendly manner.
    size_t p_start, p_end;
    for (j = 0; j < lenY; ++j) {
        p_start = Ap[j];
        p_end = Ap[j + 1];
        double y_val = Y[j * incY];  // Load once
        for (p = p_start; p < p_end; ++p) {
            y_val += alpha * Ad[p] * X[Ai[p] * incX];
        }
        Y[j * incY] = y_val;  // Store once
    }
}
