#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *C;
int ldc;
int i;
int j;
float beta_real;
float beta_imag;

void init_vars() {
    beta_real = 1.5f;
    beta_imag = 0.8f;

    N = 2048;
    ldc = N;

    size_t total_elements = N * ldc;
    size_t total_bytes = total_elements * 2 * sizeof(float);
    C = aligned_alloc(32, total_bytes);

    if (!C) {
        exit(1);
    }

    float *C_float = (float *)C;
    for (size_t idx = 0; idx < total_elements * 2; idx++) {
        C_float[idx] = (float)(idx % 128) / 128.0f;
    }
}