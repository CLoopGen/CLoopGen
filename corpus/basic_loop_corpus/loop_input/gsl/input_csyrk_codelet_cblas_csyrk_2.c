#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;
float beta_real = 1.5f;
float beta_imag = 0.8f;

void* C = NULL;

void init_vars() {
    const size_t total_size = 2 * ldc * N * sizeof(float);
    float* C_ptr = (float*)aligned_alloc(32, total_size);
    if (!C_ptr) {
        fprintf(stderr, "Failed to allocate memory for C\n");
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < 2 * ldc * N; ++idx) {
        C_ptr[idx] = (float)(idx % 128) / 64.0f;
    }

    C = (void*)C_ptr;
}