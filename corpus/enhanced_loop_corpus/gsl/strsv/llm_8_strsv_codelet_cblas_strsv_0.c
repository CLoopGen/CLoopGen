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
    float tmp1 = X[ix];
    float tmp2 = 0.0f;
    jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const float Aij = A[lda * i + j];
        tmp1 -= Aij * X[jx];
        if (j + 1 < N) {
            const float Aij_next = A[lda * i + j + 1];
            tmp2 -= Aij_next * X[jx + incX];
            j += 1;
            jx += 2 * incX;
        } else {
            jx += incX;
        }
    }
    tmp1 += tmp2; // Combine partial results to maintain computational flow
    if (nonunit) {
        X[ix] = tmp1 / A[lda * i + i];
    } else {
        X[ix] = tmp1;
    }
    ix -= incX;
}
}
