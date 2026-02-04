#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *Ap;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N - 1; i > 0 && i--;) {
    float tmp = X[ix];
    int jx = ix + incX;
    // Change to consecutive memory access by precomputing base index and using unit stride
    int base_jx = jx / incX;  // Assuming incX != 0 and consistent indexing
    for (j = i + 1; j < N; j++) {
        // Flatten Ap access with simplified arithmetic and use j as offset from i+1
        int flat_idx = (i*(2*N - i + 1)) / 2 + (j - i) - 1; // Pre-simplified index calculation
        tmp -= Ap[flat_idx] * X[base_jx + (j - (i + 1))];  // Consecutive access in X via base pointer
    }
    if (nonunit) {
        int diag_idx = (i*(2*N - i + 1)) / 2 - 1;
        X[ix] = tmp / Ap[diag_idx];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
