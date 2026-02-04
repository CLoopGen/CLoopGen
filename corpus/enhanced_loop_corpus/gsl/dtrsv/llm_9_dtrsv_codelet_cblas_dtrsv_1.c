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
    int unroll_factor = 4;
    int remainder = i % unroll_factor;
    // Unrolled loop for main part
    for (j = 0; j < remainder; j++) {
        const double Aij = A[lda * i + j];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    // Fully unrolled by 4
    for (; j + 3 < i; j += 4) {
        const double Aij1 = A[lda * i + j];
        const double Aij2 = A[lda * i + j + 1];
        const double Aij3 = A[lda * i + j + 2];
        const double Aij4 = A[lda * i + j + 3];
        tmp -= Aij1 * X[jx]; jx += incX;
        tmp -= Aij2 * X[jx]; jx += incX;
        tmp -= Aij3 * X[jx]; jx += incX;
        tmp -= Aij4 * X[jx]; jx += incX;
    }
    // Tail handling
    for (; j < i; j++) {
        const double Aij = A[lda * i + j];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
