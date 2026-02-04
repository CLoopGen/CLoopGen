#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using indirect indexing via an index array
    // Simulate indirect access pattern even if not strictly necessary, to demonstrate flexibility.
    // Assume we precomputed indices for lower triangular row-major storage (though not passed in, we simulate on-stack)

    int *indices = (int*)malloc(N * N * sizeof(int)); // Conservative allocation for linearized indices
    int p = 0;
    int i, j;
    // Precompute linear indices for lower triangle in row-major order
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            indices[p++] = ldc * i + j;
        }
    }
    // Now zero out using indirect addressing
    for (i = 0; i < p; i++) {
        C[indices[i]] = 0.0f;
    }
    free(indices);
}
