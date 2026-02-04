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
for (i = 0; i < N; i++) {
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
