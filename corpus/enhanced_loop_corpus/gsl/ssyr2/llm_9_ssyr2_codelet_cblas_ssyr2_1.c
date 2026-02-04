#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    const float tmp1_0 = alpha * X[ix];
    const float tmp2_0 = alpha * Y[iy];
    const float tmp1_1 = (i+1 < N) ? alpha * X[ix + incX] : 0.0f;
    const float tmp2_1 = (i+1 < N) ? alpha * Y[iy + incY] : 0.0f;
    int jx0 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy0 = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    int jx1 = jx0;
    int jy1 = jy0;
    for (j = 0; j <= i; j++) {
        A[lda * i + j] += tmp1_0 * Y[jy0] + tmp2_0 * X[jx0];
        if (i + 1 < N) {
            A[lda * (i + 1) + j] += tmp1_1 * Y[jy1] + tmp2_1 * X[jx1];
        }
        jx0 += incX;
        jy0 += incY;
        jx1 += incX;
        jy1 += incY;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
