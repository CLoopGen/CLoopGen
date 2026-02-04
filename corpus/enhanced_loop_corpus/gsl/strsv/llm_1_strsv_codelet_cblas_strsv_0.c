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
        jx = ix + incX;
        int unrolled = ((N - (i + 1)) / 4) * 4 + (i + 1);
        for (j = i + 1; j < unrolled; j += 4) {
            const float Aij0 = A[lda * i + j];
            const float Aij1 = A[lda * i + j + 1];
            const float Aij2 = A[lda * i + j + 2];
            const float Aij3 = A[lda * i + j + 3];
            tmp -= Aij0 * X[jx] + Aij1 * X[jx + incX] + Aij2 * X[jx + 2*incX] + Aij3 * X[jx + 3*incX];
            jx += 4 * incX;
        }
        for (; j < N; j++) {
            const float Aij = A[lda * i + j];
            tmp -= Aij * X[jx];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = tmp / A[lda * i + i];
        } else {
            X[ix] = tmp;
        }
        ix -= incX;
    }
}
