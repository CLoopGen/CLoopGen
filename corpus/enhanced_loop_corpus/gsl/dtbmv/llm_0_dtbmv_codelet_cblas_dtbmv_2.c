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
    double temp = 0.;
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    if (j_min < j_max) {
        for (int k = j_min; k < j_max; k++) {
            j = k;
            temp += X[jx] * A[lda * j + (i - j)];
            jx += incX;
        }
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + 0];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
}
}
