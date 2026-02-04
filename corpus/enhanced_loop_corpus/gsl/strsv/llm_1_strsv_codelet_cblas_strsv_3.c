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
        for (int k = i + 1, jx_inner = ix + incX; k < N; k++, jx_inner += incX) {
            const float Aji = A[lda * k + i];
            tmp -= Aji * X[jx_inner];
        }
        if (nonunit) {
            X[ix] = tmp / A[lda * i + i];
        } else {
            X[ix] = tmp;
        }
        ix -= incX;
    }
}
