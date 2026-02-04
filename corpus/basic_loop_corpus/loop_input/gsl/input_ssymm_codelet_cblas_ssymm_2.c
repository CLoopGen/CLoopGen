#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.5f;

int n1 = 200;
int n2 = 200;

int lda = 200;
int ldb = 200;
int ldc = 200;

float *A;
float *B;
float *C;

int i, j, k;

void init_vars() {
    A = (float*)aligned_alloc(32, sizeof(float) * n1 * lda);
    B = (float*)aligned_alloc(32, sizeof(float) * n1 * ldb);
    C = (float*)aligned_alloc(32, sizeof(float) * n1 * ldc);

    for (int idx = 0; idx < n1 * lda; idx++) {
        A[idx] = (float)(rand() % 100) / 10.0f;
    }
    for (int idx = 0; idx < n1 * ldb; idx++) {
        B[idx] = (float)(rand() % 100) / 10.0f;
    }
    for (int idx = 0; idx < n1 * ldc; idx++) {
        C[idx] = (float)(rand() % 100) / 10.0f;
    }

    alpha = 1.5f;
    i = 0;
    j = 0;
    k = 0;
}