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
    int offset = i;
    for (j = 0; j < i; j++) {
        const double Aji = A[offset]; // Column-major consecutive access via precomputed index
        tmp -= Aji * X[jx];
        jx += incX;
        offset += lda; // Stride by lda to access next row in column i
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
