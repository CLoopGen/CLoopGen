#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N <= 0) return;
for (i = N - 1; i >= 0; i--) {
    float tmp = X[ix];
    jx = ix + incX;
    int unroll_factor = 4;
    for (j = i + 1; j < N - unroll_factor + 1; j += unroll_factor) {
        tmp -= A[lda * i + j] * X[jx];
        tmp -= A[lda * i + j + 1] * X[jx + incX];
        tmp -= A[lda * i + j + 2] * X[jx + 2*incX];
        tmp -= A[lda * i + j + 3] * X[jx + 3*incX];
        jx += unroll_factor * incX;
    }
    for (; j < N; j++) {
        const float Aij = A[lda * i + j];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    if (nonunit && A[lda * i + i] != 0.0f) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
