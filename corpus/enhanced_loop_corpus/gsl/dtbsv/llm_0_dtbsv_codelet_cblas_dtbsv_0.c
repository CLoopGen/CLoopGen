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
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int unroll_factor = 2;
    int remainder = (j_max - j_min) % unroll_factor;
    j = j_min;
    for (; j < j_min + remainder; j++) {
        const double Aij = A[lda * i + (j - i)];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    for (; j + (unroll_factor - 1) < j_max; j += unroll_factor) {
        const double Aij0 = A[lda * i + (j - i)];
        const double Aij1 = A[lda * i + (j + 1 - i)];
        tmp -= Aij0 * X[jx] + Aij1 * X[jx + incX];
        jx += incX * unroll_factor;
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + 0];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
