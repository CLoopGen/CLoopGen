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
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N > 0) {
    for (i = N - 1; i >= 0; i--) {
        double tmp = X[ix];
        for (j = i + 1; j < ((N) < (i + K + 1) ? (N) : (i + K + 1)); j++) {
            const int offset_A = (K + i - j) + lda * j;
            const int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j * incX;
            tmp -= A[offset_A] * X[jx];
        }
        if (nonunit) {
            X[ix] = tmp / A[K + lda * i];
        } else {
            X[ix] = tmp;
        }
        ix -= incX;
    }
}
}
