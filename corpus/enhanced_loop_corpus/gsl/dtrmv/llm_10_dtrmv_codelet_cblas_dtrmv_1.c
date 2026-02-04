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
for (i = N; i > 0; i -= 2) {
    if (i == 1) {
        double temp = 0.;
        const int j_min = 0;
        const int j_max = 1;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            temp += X[jx] * A[lda * i + j];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = temp + X[ix] * A[lda * i + i];
        } else {
            X[ix] += temp;
        }
        ix -= incX;
        break;
    }
    // Process two rows per iteration
    for (int k = 0; k < 2; k++) {
        double temp = 0.;
        const int j_min = 0;
        const int j_max = i - k;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            temp += X[jx] * A[lda * (i - k) + j];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = temp + X[ix] * A[lda * (i - k) + (i - k)];
        } else {
            X[ix] += temp;
        }
        ix -= incX;
    }
}
}
