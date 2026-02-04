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
    if (i + 1 < N) {
        jx = ix + incX;
        for (j = i + 1; j < N; j++) {
            const float Aji = A[lda * j + i];
            tmp -= Aji * X[jx];
            jx += incX;
        }
    }
    if (nonunit && A[lda * i + i] != 0.0f) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
