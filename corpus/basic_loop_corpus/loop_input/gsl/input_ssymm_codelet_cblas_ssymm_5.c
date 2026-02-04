#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
    A = (float*)aligned_alloc(32, sizeof(float) * n2 * lda);
    B = (float*)aligned_alloc(32, sizeof(float) * n1 * ldb);
    C = (float*)aligned_alloc(32, sizeof(float) * n1 * ldc);

    for (int idx = 0; idx < n2 * lda; idx++) {
        A[idx] = (float)(idx % 100) / 100.0f;
    }
    for (int idx = 0; idx < n1 * ldb; idx++) {
        B[idx] = (float)(idx % 100) / 50.0f;
    }
    for (int idx = 0; idx < n1 * ldc; idx++) {
        C[idx] = (float)(idx % 100) / 25.0f;
    }
}