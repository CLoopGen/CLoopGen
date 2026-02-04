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
for (i = 0; i < N; i += 2) {
    float temp1 = 0.;
    float temp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int jx1 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + (i + 1) * incX;
    int jx2 = jx1 + incX;
    for (j = j_min; j < j_max; j++) {
        temp1 += X[jx1] * A[lda * j + i];
        if (i + 1 < N) {
            temp2 += X[jx2] * A[lda * j + i + 1];
        }
        jx1 += incX;
        jx2 += incX;
    }
    if (nonunit) {
        X[ix] = temp1 + X[ix] * A[lda * i + i];
        if (i + 1 < N) {
            ix += incX;
            X[ix] = temp2 + X[ix] * A[lda * (i + 1) + (i + 1)];
        }
    } else {
        X[ix] += temp1;
        if (i + 1 < N) {
            ix += incX;
            X[ix] += temp2;
        }
    }
    ix += incX;
}
}
