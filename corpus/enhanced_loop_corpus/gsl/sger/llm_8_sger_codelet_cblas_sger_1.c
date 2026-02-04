#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float *A;
extern  int lda;
extern int i;
extern int j;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j += 2) {
    const float tmp0 = alpha * Y[jy];
    const float tmp1 = (j + 1 < N) ? alpha * Y[jy + incY] : 0.0f;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        A[i + lda * j] += X[ix] * tmp0;
        if (j + 1 < N) {
            A[i + lda * (j + 1)] += X[ix] * tmp1;
        }
        ix += incX;
    }
    jy += 2 * incY;
}
}
