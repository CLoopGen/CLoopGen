#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const float tmp = alpha * X[ix];
    int jx = ix;
    int unroll_factor = 4;
    j = i;
    for (; j <= N - unroll_factor; j += unroll_factor) {
        A[lda * i + j]     += X[jx]             * tmp;
        A[lda * i + j + 1] += X[jx + incX]       * tmp;
        A[lda * i + j + 2] += X[jx + 2*incX]     * tmp;
        A[lda * i + j + 3] += X[jx + 3*incX]     * tmp;
        jx += 4 * incX;
    }
    for (; j < N; j++) {
        A[lda * i + j] += X[jx] * tmp;
        jx += incX;
    }
    ix += incX;
}
}
