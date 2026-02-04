#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef float real_t;

real_t *A;
real_t s;

void init_vars() {
    const int array_size = 64 * 1024 * 1024 / sizeof(real_t); // ~64MB to target ~0.01s runtime
    A = (real_t*)aligned_alloc(32, array_size * sizeof(real_t));
    if (!A) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < array_size; i++) {
        A[i] = 1.0f; // Initialize with non-zero to ensure meaningful computation
    }
    s = 0.0f;
}