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
    lda = n1;
    ldb = n2;
    nonunit = 1;

    A = (float*)aligned_alloc(32, sizeof(float) * lda * n1);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n1);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = 1.0f + (idx % 16) * 0.1f;
    }
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (idx % 64) * 0.5f;
    }
}