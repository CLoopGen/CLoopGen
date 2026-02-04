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
    n1 = 512;
    n2 = 512;
    lda = n1;
    ldb = n2;
    nonunit = 1;

    A = (float*)aligned_alloc(32, sizeof(float) * lda * n1);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n2);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = 1.0f + (idx % 100) * 0.01f;
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (idx % 200) * 0.05f;
    }
}