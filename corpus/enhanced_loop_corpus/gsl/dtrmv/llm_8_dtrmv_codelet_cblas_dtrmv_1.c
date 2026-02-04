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
for (i = N; i > 0 && i--;) {
    double temp1 = 0.0, temp2 = 0.0;
    const int j_min = 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int k;
    for (j = j_min, k = j_min + 1; j < j_max - 1; j += 2, k += 2) {
        temp1 += X[jx] * A[lda * i + j];
        temp2 += X[jx + incX] * A[lda * i + k];
        jx += 2 * incX;
    }
    for (; j < j_max; j++) {
        temp1 += X[jx] * A[lda * i + j];
        jx += incX;
    }
    double temp = temp1 + temp2;
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
}
}
