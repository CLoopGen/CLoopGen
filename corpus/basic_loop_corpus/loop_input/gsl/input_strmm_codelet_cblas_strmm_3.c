#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.5f;

int n1 = 512;
int n2 = 512;
int lda = 512;
int ldb = 512;
int nonunit = 1;

int i, j, k;

float *A;
float *B;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * lda * n1);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n2);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (float)(rand() % 100) / 10.0f;
    }

    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (float)(rand() % 100) / 10.0f;
    }

    alpha = 1.2f;
    nonunit = 1;
}