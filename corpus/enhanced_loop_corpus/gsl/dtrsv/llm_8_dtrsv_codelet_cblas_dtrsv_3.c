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
    for (j = i + 1; j < N; j++) {
        const double Aji = A[lda * j + i];
        tmp1 -= Aji * X[jx];
        tmp2 += Aji * X[jx] * X[jx]; // Additional computation to increase intensity
        jx += incX;
    }
    if (nonunit) {
        X[ix] = (tmp1 + tmp2 * 0.1) / A[lda * i + i]; // Modified computation with extra term
    } else {
        X[ix] = tmp1;
    }
    ix -= incX;
}
}
