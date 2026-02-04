#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.5f;

int n1 = 400;
int n2 = 300;
int lda = 400;
int ldb = 300;
int nonunit = 1;
int i, j, k;

float *A;
float *B;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * n1);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n1);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (float)(idx % 128) / 64.0f - 1.0f;
    }

    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (float)(idx % 128) / 64.0f - 1.0f;
    }

    alpha = 1.5f;
    nonunit = 1;
}