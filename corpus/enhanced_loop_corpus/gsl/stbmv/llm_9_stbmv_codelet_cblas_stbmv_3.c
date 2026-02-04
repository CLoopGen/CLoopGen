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
for (i = 0; i < N; i += 2) {
    float temp0 = 0.;
    float temp1 = 0.;
    const int j_min0 = i + 1;
    const int j_max0 = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    const int j_min1 = (i+1) + 1;
    const int j_max1 = ((N) < (i+1 + K + 1) ? (N) : (i+1 + K + 1));
    int jx0 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min0 * incX;
    int jx1 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min1 * incX;
    for (j = j_min0; j < j_max0 && j < j_min1; j++) {
        temp0 += X[jx0] * A[lda * j + (K - j + i)];
        jx0 += incX;
    }
    for (j = j_min1; j < j_max1; j++) {
        temp1 += X[jx1] * A[lda * j + (K - j + (i+1))];
        jx1 += incX;
    }
    if (nonunit) {
        X[ix] = temp0 + X[ix] * A[lda * i + K];
    } else {
        X[ix] += temp0;
    }
    ix += incX;
    if (i+1 < N) {
        if (nonunit) {
            X[ix] = temp1 + X[ix] * A[lda * (i+1) + K];
        } else {
            X[ix] += temp1;
        }
        ix += incX;
    }
}
}
