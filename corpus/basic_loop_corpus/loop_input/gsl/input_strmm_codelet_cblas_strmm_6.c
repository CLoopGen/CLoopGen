#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.5f;

int n1 = 200;
int n2 = 250;
int lda = 256;
int ldb = 256;
int nonunit = 1;
int i, j, k;

float *A;
float *B;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * n2);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n1);

    for (int idx = 0; idx < lda * n2; idx++) {
        A[idx] = (float)(idx % 100) * 0.1f;
    }

    for (int idx = 0; idx < ldb * n1; idx++) {
        B[idx] = (float)(idx % 200) * 0.05f;
    }

    alpha = 1.5f;
    nonunit = 1;
}