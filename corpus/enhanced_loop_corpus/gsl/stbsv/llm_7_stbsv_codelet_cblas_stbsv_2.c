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
float *restrict local_X = X;
const float *restrict local_A = A;
for (i = 0; i < N; i++) {
    float tmp = local_X[ix];
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    for (int k = j_min; k < j_max; k++) {
        const float Aji = local_A[(i - k) + lda * k];
        tmp = tmp - Aji * local_X[jx];
        jx += incX;
    }
    if (nonunit) {
        tmp = tmp / local_A[lda * i];
    }
    local_X[ix] = tmp;
    ix += incX;
}
}
