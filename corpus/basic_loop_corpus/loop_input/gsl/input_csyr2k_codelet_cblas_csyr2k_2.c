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

    size_t matrix_size = (size_t)ldc * N;
    float *C_data = (float *)aligned_alloc(32, 2 * matrix_size * sizeof(float));
    if (!C_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < 2 * matrix_size; ++idx) {
        C_data[idx] = (float)(idx % 127) / 10.0f;
    }

    C = C_data;
}