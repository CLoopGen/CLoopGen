#include <stdlib.h>
#include <math.h>

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
    n1 = 400;
    n2 = 400;
    lda = n1;
    ldb = n1;
    ldc = n1;

    alpha = 1.5f;

    A = (float*)aligned_alloc(32, sizeof(float) * lda * n1);
    B = (float*)aligned_alloc(32, sizeof(float) * ldb * n2);
    C = (float*)aligned_alloc(32, sizeof(float) * ldc * n2);

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (float)((rand() % 1000) / 100.0);
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (float)((rand() % 1000) / 100.0);
    }
    for (int idx = 0; idx < ldc * n2; idx++) {
        C[idx] = (float)((rand() % 1000) / 100.0);
    }
}