#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 512;
int K = 256;
void *A;
int lda = 256;
void *B;
int ldb = 256;
void *C;
int ldc = 512;
int i;
int j;
int k;
double alpha_real = 1.5;
double alpha_imag = 0.8;

void init_vars() {
    const size_t A_size = (size_t)N * lda * 2 * sizeof(double);
    const size_t B_size = (size_t)N * ldb * 2 * sizeof(double);
    const size_t C_size = (size_t)N * ldc * 2 * sizeof(double);

    A = aligned_alloc(32, A_size);
    B = aligned_alloc(32, B_size);
    C = aligned_alloc(32, C_size);

    srand((unsigned int)time(NULL));

    double *A_ptr = (double *)A;
    double *B_ptr = (double *)B;
    double *C_ptr = (double *)C;

    for (size_t idx = 0; idx < A_size / sizeof(double); idx++) {
        A_ptr[idx] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }

    for (size_t idx = 0; idx < B_size / sizeof(double); idx++) {
        B_ptr[idx] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }

    for (size_t idx = 0; idx < C_size / sizeof(double); idx++) {
        C_ptr[idx] = (double)(rand()) / RAND_MAX * 2.0 - 1.0;
    }
}