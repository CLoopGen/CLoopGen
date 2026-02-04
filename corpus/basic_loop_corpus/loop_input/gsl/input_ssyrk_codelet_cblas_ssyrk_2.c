#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float beta;
float *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 1024;  // Size to ensure ~0.01 sec runtime on modern CPU
    beta = 1.5f;
    ldc = N;
    
    // Allocate C as a column-major matrix of size ldc x N
    C = (float*)aligned_alloc(32, sizeof(float) * ldc * N);
    if (!C) {
        exit(1);
    }

    // Initialize C with non-zero values to make scaling observable
    for (int idx = 0; idx < ldc * N; idx++) {
        C[idx] = (float)(idx % 128 + 1);
    }
}