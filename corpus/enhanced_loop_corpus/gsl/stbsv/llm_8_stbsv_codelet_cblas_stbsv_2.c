#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    if (i + 1 < N) {
        float tmp1 = X[ix];
        float tmp2 = X[ix + incX];
        const int j_min = (K > i ? 0 : i - K);
        const int j_max = i;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            const float Aji1 = A[(i - j) + lda * j];
            const float Aji2 = A[(i + 1 - j) + lda * j];
            tmp1 -= Aji1 * X[jx];
            tmp2 -= Aji2 * X[jx];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = tmp1 / A[0 + lda * i];
            X[ix + incX] = tmp2 / A[0 + lda * (i + 1)];
        } else {
            X[ix] = tmp1;
            X[ix + incX] = tmp2;
        }
        ix += 2 * incX;
    } else {
        float tmp = X[ix];
        const int j_min = (K > i ? 0 : i - K);
        const int j_max = i;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            const float Aji = A[(i - j) + lda * j];
            tmp -= Aji * X[jx];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = tmp / A[0 + lda * i];
        } else {
            X[ix] = tmp;
        }
        ix += incX;
    }
}
}
