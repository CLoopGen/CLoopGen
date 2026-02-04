#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < N; i++) {
    float tmp = X[ix];
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int index_A = lda * i;
    for (j = 0; j < i; j++) {
        const float Aij = A[index_A + j];
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
