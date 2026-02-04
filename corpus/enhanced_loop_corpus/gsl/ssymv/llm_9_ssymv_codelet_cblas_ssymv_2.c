#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    float temp1_0 = alpha * X[ix];
    float temp1_1 = (i + 1 < N) ? alpha * X[ix + incX] : 0.0f;
    float temp2_0 = 0.0f;
    float temp2_1 = 0.0f;
    const int j_min = i + 1;
    const int j_max = N;
    int jx_0 = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy_0 = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j_min * incY;
    Y[iy] += temp1_0 * A[lda * i + i];
    if (i + 1 < N) {
        Y[iy + incY] += temp1_1 * A[lda * (i + 1) + (i + 1)];
    }
    for (j = j_min; j < j_max; j++) {
        Y[jy_0] += temp1_0 * A[lda * i + j];
        temp2_0 += X[jx_0] * A[lda * i + j];
        if (i + 1 < N) {
            const int offset = lda * (i + 1) + j;
            Y[jy_0] += temp1_1 * A[offset];
            temp2_1 += X[jx_0] * A[offset];
        }
        jx_0 += incX;
        jy_0 += incY;
    }
    Y[iy] += alpha * temp2_0;
    if (i + 1 < N) {
        Y[iy + incY] += alpha * temp2_1;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
