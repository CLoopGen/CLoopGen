#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float tmp = X[ix];
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int unroll_factor = 2;
    j = j_min;
    for (; j + unroll_factor <= j_max; j += unroll_factor) {
        const float Aij0 = A[lda * i + (K + j - i)];
        const float Aij1 = A[lda * i + (K + j + 1 - i)];
        tmp -= Aij0 * X[jx] + Aij1 * X[jx + incX];
        jx += incX * 2;
    }
    for (; j < j_max; j++) {
        const float Aij = A[lda * i + (K + j - i)];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + K];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
