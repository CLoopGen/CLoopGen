#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dims_count;
float *src;
float *dst;
float *src1;

void init_vars() {
    dims_count = 8388608; // Approximately 32 MB of float data (8388608 * sizeof(float) * 3 ≈ 96 MB), should run in ~0.01s

    src = (float *)aligned_alloc(32, dims_count * sizeof(float));
    dst = (float *)aligned_alloc(32, dims_count * sizeof(float));
    src1 = (float *)aligned_alloc(32, dims_count * sizeof(float));

    for (int i = 0; i < dims_count; ++i) {
        src[i] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
        src1[i] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
        dst[i] = 0.0f;
    }
}