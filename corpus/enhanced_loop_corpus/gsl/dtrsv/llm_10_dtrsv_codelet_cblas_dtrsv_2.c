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
if (N <= 1) return;
double sum = 0.0;
jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
for (i = 1; i < N; i++) {
    for (j = 0; j < i; j++) {
        sum += A[lda * j + i] * X[jx + j * incX];
    }
    double tmp = X[ix] - sum;
    if (nonunit) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
