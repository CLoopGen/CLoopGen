#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *C;
int ldc;
int i;
int j;
int n1;
int n2;
float beta_real;
float beta_imag;

void init_vars() {
    beta_real = 1.5f;
    beta_imag = 0.8f;

    n1 = 4096;
    n2 = 4096;
    ldc = n2;

    size_t data_size = 2 * (size_t)ldc * n1 * sizeof(float);
    C = aligned_alloc(32, data_size);
    if (!C) {
        exit(1);
    }

    float *C_float = (float *)C;
    for (int idx = 0; idx < 2 * ldc * n1; idx++) {
        C_float[idx] = (float)(idx % 127) / 10.0f;
    }
}