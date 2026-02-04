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
double *restrict local_X = X;
const double *restrict local_A = A;
for (i = N - 1; i > 0 && i--;) {
    double tmp = local_X[ix];
    jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const double Aji = local_A[lda * j + i];
        tmp -= Aji * local_X[jx];
        jx += incX;
    }
    if (nonunit) {
        local_X[ix] = tmp / local_A[lda * i + i];
    } else {
        local_X[ix] = tmp;
    }
    ix -= incX;
}
}
