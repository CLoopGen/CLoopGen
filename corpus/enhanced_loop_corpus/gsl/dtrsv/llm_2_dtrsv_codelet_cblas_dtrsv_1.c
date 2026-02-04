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
for (i = 1; i < N; i++) {
    double tmp = X[ix];
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int offset = lda * i;
    for (j = 0; j < i; j++) {
        const double Aij = A[offset + j];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[offset + i];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
