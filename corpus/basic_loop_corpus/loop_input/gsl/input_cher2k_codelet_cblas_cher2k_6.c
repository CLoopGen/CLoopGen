#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int N = 512;
int K = 512;
int lda = 512;
int ldb = 512;
float alpha_real = 1.0f;
float alpha_imag = 0.5f;

void* A = NULL;
void* B = NULL;
void* C = NULL;

int i, j, k;

void init_vars() {
    const size_t elem_size = sizeof(float);
    const size_t matrix_size = 2 * N * N * elem_size; // complex float: 2 floats per element

    // Allocate aligned memory for A, B, C (complex matrices of size N x N)
    A = aligned_alloc(64, matrix_size);
    B = aligned_alloc(64, matrix_size);
    C = aligned_alloc(64, matrix_size);

    // Initialize A, B, C to zero
    memset(A, 0, matrix_size);
    memset(B, 0, matrix_size);
    memset(C, 0, matrix_size);

    // Initialize with sample data to ensure realistic memory access patterns
    float* A_ptr = (float*)A;
    float* B_ptr = (float*)B;
    float* C_ptr = (float*)C;

    for (int idx = 0; idx < 2 * N * N; idx++) {
        A_ptr[idx] = (rand() / (float)RAND_MAX) * 0.1f;
        B_ptr[idx] = (rand() / (float)RAND_MAX) * 0.1f;
        C_ptr[idx] = (rand() / (float)RAND_MAX) * 0.01f;
    }

    // Ensure loop bounds are safe: k < K, i < N, j < N, and accesses use lda/ldb
    // Matrix A is accessed as A[k * lda + i], so we require K <= N if lda == N
    // Current values: N=512, K=512, lda=512, ldb=512 — all safe
}