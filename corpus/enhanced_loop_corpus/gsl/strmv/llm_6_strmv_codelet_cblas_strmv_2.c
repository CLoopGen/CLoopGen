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
for (i = N; i > 0 && i--;) {
    float temp1 = 0., temp2 = 0.;
    const int j_min = 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp1 += X[jx] * A[lda * j + i];
        jx += incX;
    }
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp2 += X[jx] * A[lda * j + i - (i > 0)]; // Introduce slight index variation (RAW dependency modified)
        jx += incX;
    }
    temp1 = (temp1 + temp2) * 0.5f; // Combine results to preserve approximate semantics
    if (nonunit) {
        X[ix] = temp1 + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp1;
    }
    ix -= incX;
}
}
