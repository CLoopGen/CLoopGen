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
    double temp1 = 0., temp2 = 0.;
    const int j_min = 0;
    const int j_max = i - (i % 2);  // Make even for dual accumulation
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j += 2) {
        temp1 += X[jx] * A[lda * i + j];
        if (j + 1 < j_max) {
            temp2 += X[jx + incX] * A[lda * i + j + 1];
        }
        jx += 2 * incX;
    }
    temp1 += temp2;  // Combine partial sums
    if (nonunit) {
        X[ix] = temp1 + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp1;
    }
    ix -= incX;
}
}
