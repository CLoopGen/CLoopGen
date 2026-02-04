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
    float tmp1 = X[ix];
    float tmp2 = 0.0f;
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const float Aij = A[lda * i + (K + j - i)];
        tmp1 -= Aij * X[jx];
        tmp2 += Aij * Aij; // Additional computation: sum of squares of Aij
        jx += incX;
    }
    if (nonunit) {
        float diag = A[lda * i + K];
        X[ix] = (tmp1) / (diag + 1e-8f); // Slight numerical stabilization
    } else {
        X[ix] = tmp1;
    }
    ix += incX;
}
}
