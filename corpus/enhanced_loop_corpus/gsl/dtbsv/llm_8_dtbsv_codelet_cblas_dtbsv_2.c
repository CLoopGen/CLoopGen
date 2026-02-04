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
for (i = 0; i < N; i++) {
    double tmp1 = X[ix];
    double tmp2 = 0.0;
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max - 1; j += 2) {
        const double Aji1 = A[(i - j) + lda * j];
        const double Aji2 = A[(i - (j+1)) + lda * (j+1)];
        tmp1 -= Aji1 * X[jx];
        tmp2 -= Aji2 * X[jx + incX];
        jx += 2 * incX;
    }
    for (; j < j_max; j++) {
        const double Aji = A[(i - j) + lda * j];
        tmp1 -= Aji * X[jx];
        jx += incX;
    }
    tmp1 += tmp2;
    if (nonunit) {
        X[ix] = tmp1 / A[0 + lda * i];
    } else {
        X[ix] = tmp1;
    }
    ix += incX;
}
}
