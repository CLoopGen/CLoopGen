#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 2048;
int K = 512;
float *A;
int lda = 1024;
float *X;
int incX = 1;
int nonunit = 1;
int i;
int j;
int ix;

void init_vars() {
    const size_t A_size = (size_t)lda * N;
    A = (float*)aligned_alloc(32, A_size * sizeof(float));
    X = (float*)aligned_alloc(32, N * sizeof(float));

    for (size_t idx = 0; idx < A_size; ++idx) {
        A[idx] = (float)(drand48());
    }

    for (int idx = 0; idx < N; ++idx) {
        X[idx] = (float)(drand48());
    }

    ix = 0;
}