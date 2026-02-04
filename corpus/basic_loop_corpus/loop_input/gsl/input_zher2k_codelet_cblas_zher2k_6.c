#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 512;
int lda = 512;
int ldb = 512;
double alpha_real = 1.0;
double alpha_imag = 0.5;

void* A;
void* B;
void* C;

int i, j, k;

void init_vars() {
    A = aligned_alloc(32, 2 * N * K * sizeof(double));
    B = aligned_alloc(32, 2 * N * K * sizeof(double));
    C = aligned_alloc(32, 2 * N * N * sizeof(double));

    double* A_ptr = (double*)A;
    double* B_ptr = (double*)B;
    double* C_ptr = (double*)C;

    for (int idx = 0; idx < 2 * N * K; idx++) {
        A_ptr[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        B_ptr[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int idx = 0; idx < 2 * N * N; idx++) {
        C_ptr[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
}