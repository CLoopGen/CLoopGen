#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.5f;

int n1 = 512;
int n2 = 512;
int nonunit = 1;
int i, j, k;
int lda = 512;
int ldb = 512;

float *A;
float *B;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * n2);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (float)(idx % 128) / 64.0f;
    }
    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (float)(idx % 128) / 64.0f;
    }
}