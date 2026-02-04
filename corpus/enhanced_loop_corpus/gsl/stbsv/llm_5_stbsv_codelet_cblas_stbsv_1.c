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
    const int j_min = i > K ? i - K : 0;
    const int j_max = i;
    if (j_min < j_max) {
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            const float Aij = A[lda * i + (K + j - i)];
            tmp -= Aij * X[jx];
            jx += incX;
        }
    }
    if (nonunit && A[lda * i + K] != 0.0f) {
        X[ix] = tmp / A[lda * i + K];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
