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
for (i = N; i > 0 && i--;) {
    double tmp = X[ix];
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx_start = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (int k = 0; k < j_max - j_min; k++) {
        int j = j_min + k;
        int jx = jx_start + k * incX;
        const double Aij = A[lda * i + (j - i)];
        tmp -= Aij * X[jx];
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + 0];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
