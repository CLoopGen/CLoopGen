#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float alpha = 1.5f;

int n1 = 200;
int n2 = 200;
int nonunit = 1;
int i, j, k;

int lda = 200;
int ldb = 200;

float *A;
float *B;

void init_vars() {
    A = (float*)calloc(lda * n1, sizeof(float));
    B = (float*)calloc(ldb * n2, sizeof(float));

    for (int idx = 0; idx < lda * n1; idx++) {
        A[idx] = (float)(idx % 123) * 0.01f;
    }
    for (int idx = 0; idx < ldb * n2; idx++) {
        B[idx] = (float)(idx % 123) * 0.01f;
    }

    alpha = 1.5f;
    nonunit = 1;
}