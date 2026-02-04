#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 512;
int K = 256;
float alpha = 1.5f;

float *A;
int lda = 256;
float *B;
int ldb = 256;
float *C;
int ldc = 512;

int i;
int j;
int k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * N * K);
    B = (float*)aligned_alloc(32, sizeof(float) * N * K);
    C = (float*)aligned_alloc(32, sizeof(float) * N * N);

    for (int idx = 0; idx < N * K; idx++) {
        A[idx] = (float)(drand48() * 2.0 - 1.0);
        B[idx] = (float)(drand48() * 2.0 - 1.0);
    }

    for (int idx = 0; idx < N * N; idx++) {
        C[idx] = (float)(drand48() * 2.0 - 1.0);
    }
}