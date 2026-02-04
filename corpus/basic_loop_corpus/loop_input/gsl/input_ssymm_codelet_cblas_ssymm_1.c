#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float beta;
float *C;
int ldc;
int i;
int j;
int n1;
int n2;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldc = n1;
    beta = 1.5f;

    size_t size_in_bytes = (size_t)ldc * n2 * sizeof(float);
    if (size_in_bytes > 256 * (1 << 20)) {
        n1 = 2048;
        n2 = 2048;
        ldc = n1;
        size_in_bytes = (size_t)ldc * n2 * sizeof(float);
    }

    C = (float*)aligned_alloc(32, size_in_bytes);
    if (!C) {
        exit(1);
    }

    for (int idx = 0; idx < n1 * n2; idx++) {
        C[idx] = (float)(idx % 128);
    }
}