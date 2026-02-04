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
if (N <= 0) return;
int i_start = 0;
while (i_start < N) {
    for (int ib = i_start; ib < i_start + 1 && ib < N; ib++) {
        i = ib;
        float tmp = X[ix];
        const int j_min = (i > K ? i - K : 0);
        const int j_max = i;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            const float Aij = A[lda * i + (K + j - i)];
            tmp -= Aij * X[jx];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = tmp / A[lda * i + K];
        } else {
            X[ix] = tmp;
        }
        ix += incX;
    }
    i_start += 1;
}
}
