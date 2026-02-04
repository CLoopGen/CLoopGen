#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float beta;
float *Y;
int incY;
int i;
int iy;

void init_vars() {
    N = 1 << 20; // 1 million elements, ~4MB for float array
    beta = 1.5f;
    incY = 1; // typical increment
    iy = 0;   // starting index

    // Allocate Y with sufficient size to cover all accesses: iy + (N-1)*incY
    int total_elements = iy + (N - 1) * incY + 1;
    Y = (float*)aligned_alloc(32, total_elements * sizeof(float));
    if (!Y) {
        exit(1);
    }

    // Initialize Y array to avoid undefined behavior
    for (int idx = 0; idx < total_elements; idx++) {
        Y[idx] = 1.0f;
    }
}