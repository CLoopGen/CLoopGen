#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;
float beta_real = 2.0f;
float beta_imag = 1.0f;

void *C;

void init_vars() {
    const size_t matrix_size = ldc * N * sizeof(float) * 2;
    C = aligned_alloc(32, matrix_size);
    if (!C) {
        exit(1);
    }

    float *C_float = (float *)C;
    for (size_t idx = 0; idx < ldc * N * 2; ++idx) {
        C_float[idx] = (float)(idx % 128) / 64.0f;
    }
}