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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M; i++) {
    const float tmp = alpha * X[ix];
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j += 2) {
        A[lda * i + j] += Y[jy] * tmp;
        if (j + 1 < N) {
            A[lda * i + j + 1] += Y[jy + incY] * tmp;
        }
        jy += 2 * incY;
    }
    ix += incX;
}
}
