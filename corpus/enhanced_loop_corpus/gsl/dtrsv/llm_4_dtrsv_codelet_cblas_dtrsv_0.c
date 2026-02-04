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
        double tmp = X[ix];
        jx = ix + incX;
        if (!nonunit && A[lda * i + i] == 0.0) {
            X[ix] = tmp;
            ix -= incX;
            continue;
        }
        for (j = i + 1; j < N; j++) {
            const double Aij = A[lda * i + j];
            tmp -= Aij * X[jx];
            jx += incX;
        }
        X[ix] = nonunit ? tmp / A[lda * i + i] : tmp;
        ix -= incX;
    }
}
