#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N - 1; i > 0 && i--;) {
    double tmp1 = X[ix];
    double tmp2 = 0.0;
    jx = ix + incX;
    for (j = i + 1; j < N; j += 2) {
        const double Aij1 = A[lda * i + j];
        tmp1 -= Aij1 * X[jx];
        jx += incX;
        if (j + 1 < N) {
            const double Aij2 = A[lda * i + j + 1];
            tmp2 -= Aij2 * X[jx];
            jx += incX;
        }
    }
    tmp1 += tmp2;
    if (nonunit) {
        X[ix] = tmp1 / A[lda * i + i];
    } else {
        X[ix] = tmp1;
    }
    ix -= incX;
}
}
