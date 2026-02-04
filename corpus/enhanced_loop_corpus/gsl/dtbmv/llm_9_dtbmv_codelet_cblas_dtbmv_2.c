#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N; i > 0 && i--;) {
    double temp1 = 0., temp2 = 0.;
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max - 1; j += 2) {
        temp1 += X[jx] * A[lda * j + (i - j)];
        jx += incX;
        temp2 += X[jx] * A[lda * (j + 1) + (i - j - 1)];
        jx += incX;
    }
    if (j < j_max) {
        temp1 += X[jx] * A[lda * j + (i - j)];
    }
    double temp = temp1 + temp2;
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + 0];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
}
}
