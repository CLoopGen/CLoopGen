#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 256;
float alpha = 1.1f;

float *A_data;
void *A;
float *C_data;
void *C;
int lda = 256;
int ldc = 512;
int i, j, k;

void init_vars() {
    const size_t A_size = (size_t)N * lda * 2; // complex numbers: 2 floats each
    const size_t C_size = (size_t)N * ldc * 2;

    A_data = (float*)aligned_alloc(32, A_size * sizeof(float));
    C_data = (float*)aligned_alloc(32, C_size * sizeof(float));

    if (!A_data || !C_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    A = (void*)A_data;
    C = (void*)C_data;

    for (size_t idx = 0; idx < A_size; ++idx) {
        A_data[idx] = (float)(idx % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < C_size; ++idx) {
        C_data[idx] = (float)(idx % 50) / 50.0f;
    }
}