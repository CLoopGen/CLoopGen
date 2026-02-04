#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int K = 256;
int lda = 256;
int ldb = 256;
int ldc = 512;
int i, j, k;
float alpha_real = 1.0f;
float alpha_imag = 0.5f;

void* A = NULL;
void* B = NULL;
void* C = NULL;

void init_vars() {
    // Allocate aligned memory for complex data: each element has real and imaginary parts (2 floats)
    A = aligned_alloc(32, sizeof(float) * 2 * N * lda);
    B = aligned_alloc(32, sizeof(float) * 2 * N * ldb);
    C = aligned_alloc(32, sizeof(float) * 2 * N * ldc);

    // Initialize A, B, C with zeros
    if (A) {
        for (int idx = 0; idx < 2 * N * lda; ++idx) {
            ((float*)A)[idx] = 0.0f;
        }
    }

    if (B) {
        for (int idx = 0; idx < 2 * N * ldb; ++idx) {
            ((float*)B)[idx] = 0.0f;
        }
    }

    if (C) {
        for (int idx = 0; idx < 2 * N * ldc; ++idx) {
            ((float*)C)[idx] = 0.0f;
        }
    }
}