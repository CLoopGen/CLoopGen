#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha;
float *A;
int lda;
float *B;
int ldb;
float *C;
int ldc;
int i;
int j;
int k;
int n1;
int n2;

void init_vars() {
    n1 = 512;
    n2 = 512;

    lda = n2;
    ldb = n1;
    ldc = n2;

    alpha = 1.5f;

    A = (float*)aligned_alloc(32, sizeof(float) * lda * n2);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n1);
    C = (float*)aligned_alloc(32, sizeof(float) * ldc * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (float)(idx % 128) * 0.01f;
    }
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (float)(idx % 128) * 0.02f;
    }
    for (int idx = 0; idx < ldc * n1; idx++) {
        C[idx] = (float)(idx % 128) * 0.03f;
    }
}