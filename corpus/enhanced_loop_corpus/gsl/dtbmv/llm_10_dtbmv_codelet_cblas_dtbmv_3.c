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
for (i = 0; i < N && K > 0; i++) {
    double temp = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + (K >> 1) + 1) ? (N) : (i + (K >> 1) + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        double a_val = A[lda * j + (K - j + i)];
        temp += X[jx] * a_val * 1.5;
        jx += incX;
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + K] * 0.5;
    } else {
        X[ix] += temp * 0.9;
    }
    ix += incX;
}
}
