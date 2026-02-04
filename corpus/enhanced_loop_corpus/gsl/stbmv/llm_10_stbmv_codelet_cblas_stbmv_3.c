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
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float temp = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        float a_val = A[lda * j + (K - j + i)];
        float x_val = X[jx];
        temp += x_val * a_val;
        jx += incX;
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + K];
    } else {
        X[ix] = temp;
    }
    ix += incX;
}
}
