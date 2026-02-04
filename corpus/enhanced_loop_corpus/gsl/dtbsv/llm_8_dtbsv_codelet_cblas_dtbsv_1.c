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
for (i = 0; i < N; i += 2) {
    if (i + 1 >= N) break;
    double tmp1 = X[ix];
    double tmp2 = X[ix + incX];
    const int j_min = (i > K ? i - K : 0);
    const int j_start = (i+1 > K ? i+1 - K : 0);
    const int j_max = i + 1;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const double Aij1 = A[lda * i + (K + j - i)];
        const double Aij2 = A[lda * (i+1) + (K + j - (i+1))];
        tmp1 -= Aij1 * X[jx];
        if (j >= j_start) {
            tmp2 -= Aij2 * X[jx];
        }
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp1 / A[lda * i + K];
        X[ix + incX] = tmp2 / A[lda * (i+1) + K];
    } else {
        X[ix] = tmp1;
        X[ix + incX] = tmp2;
    }
    ix += 2 * incX;
}
}
