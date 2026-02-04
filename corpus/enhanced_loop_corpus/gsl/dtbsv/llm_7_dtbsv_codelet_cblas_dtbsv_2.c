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
double prev_X_val = 0.0;
for (i = 0; i < N; i++) {
    double tmp = X[ix];
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const double Aji = A[(i - j) + lda * j];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = (tmp + prev_X_val) / A[lda * i];
    } else {
        X[ix] = tmp + prev_X_val;
    }
    prev_X_val = X[ix];
    ix += incX;
}
}
