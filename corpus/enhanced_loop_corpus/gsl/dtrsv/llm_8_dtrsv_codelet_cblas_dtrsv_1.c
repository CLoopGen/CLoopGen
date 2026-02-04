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
int i_start = 1;
int i_end = N - (N % 2); // Adjust trip count to even boundary for unrolling
for (i = i_start; i < i_end; i += 2) {
    double tmp1 = X[ix];
    double tmp2 = X[ix + incX];
    int jx1 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jx2 = jx1;
    for (j = 0; j < i; j++) {
        const double Aij1 = A[lda * i + j];
        const double Aij2 = A[lda * (i + 1) + j];
        tmp1 -= Aij1 * X[jx1];
        tmp2 -= Aij2 * X[jx2];
        jx1 += incX;
        jx2 += incX;
    }
    if (nonunit) {
        X[ix] = tmp1 / A[lda * i + i];
        if (i + 1 < N) {
            X[ix + incX] = tmp2 / A[lda * (i + 1) + (i + 1)];
        }
    } else {
        X[ix] = tmp1;
        if (i + 1 < N) {
            X[ix + incX] = tmp2;
        }
    }
    ix += 2 * incX;
}
// Handle leftover iteration if N is odd
if (i < N) {
    double tmp = X[ix];
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j++) {
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
