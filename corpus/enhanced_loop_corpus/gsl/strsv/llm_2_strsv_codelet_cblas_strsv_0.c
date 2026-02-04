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
for (i = N - 1; i > 0 && i--;) {
    float tmp = X[ix];
    int offset = lda * i + i + 1;
    int x_offset = jx;
    for (j = i + 1; j < N; j++) {
        const float Aij = A[offset++];
        tmp -= Aij * X[x_offset];
        x_offset += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
