#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
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
for (i = 0; i < N; i++) {
    double temp = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + (i + 1) * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[lda * j + i];
        jx += incX;
    }
    if (!nonunit) {
        X[ix] += temp;
    } else {
        double diag = A[lda * i + i];
        if (diag != 0.0) {
            X[ix] = temp + X[ix] * diag;
        }
    }
    ix += incX;
}
}
