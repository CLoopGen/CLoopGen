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
    const int unroll_factor = 4;
    const int j_min = i + 1;
    const int j_max = j_min + ((j_min + unroll_factor <= N) ? 
                              ((N - j_min) / unroll_factor) * unroll_factor : 0);
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + (i + 1) * incX;

    j = j_min;
    for (; j < j_max; j += unroll_factor) {
        temp += X[jx] * A[lda * j + i];
        temp += X[jx + incX] * A[lda * (j + 1) + i];
        temp += X[jx + 2*incX] * A[lda * (j + 2) + i];
        temp += X[jx + 3*incX] * A[lda * (j + 3) + i];
        jx += 4 * incX;
    }

    for (; j < N; j++) {
        temp += X[jx] * A[lda * j + i];
        jx += incX;
    }

    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp;
    }
    ix += incX;
}
}
