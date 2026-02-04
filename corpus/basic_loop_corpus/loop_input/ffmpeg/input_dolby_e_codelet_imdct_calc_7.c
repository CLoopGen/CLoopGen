#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *result;
int n;
int n2;
int i;

void init_vars() {
    n = 1 << 20; // 1 million elements, ~4MB for float array
    n2 = n / 2;  // Process half the array to avoid double negation and out-of-bounds

    result = (float*)aligned_alloc(32, n * sizeof(float));
    if (!result) {
        exit(1);
    }

    for (int idx = 0; idx < n; idx++) {
        result[idx] = (float)(idx % 1000) / 10.0f;
    }
}