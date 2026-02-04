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
for (i = 1; i < N; i += 2) {
    float tmp1 = X[ix];
    float tmp2 = (i + 1 < N) ? X[ix + incX] : 0.0f;
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < i; j++) {
        const float Aji1 = A[lda * j + i];
        tmp1 -= Aji1 * X[jx];
        if (i + 1 < N) {
            const float Aji2 = A[lda * j + (i + 1)];
            tmp2 -= Aji2 * X[jx];
        }
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp1 / A[lda * i + i];
        if (i + 1 < N) {
            X[ix + incX] = tmp2 / A[lda * (i + 1) + (i + 1)];
        }
    } else {
        X[ix] = tmp1;
        if (i + 1 < N) {
            X[ix + incX] = tmp2;
        }
    }
    ix += incX;
    if (i + 1 < N) ix += incX;
}
}
