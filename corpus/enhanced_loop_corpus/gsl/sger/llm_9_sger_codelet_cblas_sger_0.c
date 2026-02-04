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
for (i = 0; i < M; i += 2) {
    int iy1 = ix;
    int iy2 = incX > 0 ? ix + incX : ix - incX;
    const float tmp1 = alpha * X[iy1];
    const float tmp2 = (i + 1 < M) ? alpha * X[iy2] : 0.0f;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        A[lda * i + j] += Y[jy] * tmp1;
        if (i + 1 < M) {
            A[lda * (i + 1) + j] += Y[jy] * tmp2;
        }
        jy += incY;
    }
    ix += 2 * incX;
}
}
