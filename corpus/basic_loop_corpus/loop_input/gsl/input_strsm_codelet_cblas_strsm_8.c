#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *A;
int lda;
float *B;
int ldb;
int i;
int j;
int k;
int n1;
int n2;
int nonunit;

void init_vars() {
    n1 = 1024;
    n2 = 512;
    lda = n2;
    ldb = n2;
    nonunit = 1;

    A = (float*)aligned_alloc(32, sizeof(float) * lda * n2);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = 1.0f + 0.01f * (idx % 100);
    }

    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = 2.0f + 0.02f * (idx % 200);
    }
}