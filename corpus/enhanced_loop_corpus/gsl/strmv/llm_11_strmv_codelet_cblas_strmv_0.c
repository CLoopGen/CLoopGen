#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
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
    const int j_min = (i + 1) / 2;  // Reduced lower bound to increase trip count and reuse
    const int j_max = N;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        float a_val = A[lda * i + j];
        temp += X[jx] * a_val * 1.5f;  // Increased arithmetic intensity with extra multiply
        jx += incX;
    }
    temp *= 0.9f;  // Additional scaling applied once per outer loop

    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i] * 1.1f;
    } else {
        X[ix] += temp;
    }
    ix += incX;
}
}
