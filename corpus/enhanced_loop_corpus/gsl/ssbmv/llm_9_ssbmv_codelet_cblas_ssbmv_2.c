#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
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
    float tmp1_0 = alpha * X[ix];
    float tmp1_1 = (i + 1 < N) ? alpha * X[ix + incX] : 0.0f;
    float tmp2_0 = 0.0f, tmp2_1 = 0.0f;
    const int j_min = i + 1;
    const int j_max_0 = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    const int j_max_1 = (i + 1 < N) ? ((N) < (i + K + 2) ? (N) : (i + K + 2)) : 0;
    int jx_0 = ((incX > 0) ? 0 : (N - 1) * (-incX)) + j_min * incX;
    int jy_0 = ((incY > 0) ? 0 : (N - 1) * (-incY)) + j_min * incY;
    int jx_1 = jx_0 + incX;
    int jy_1 = jy_0 + incY;

    Y[iy] += tmp1_0 * A[i * lda];
    if (i + 1 < N) {
        Y[iy + incY] += tmp1_1 * A[(i + 1) * lda];
    }

    for (j = j_min; j < j_max_0; j++) {
        float Aij_0 = A[(j - i) + i * lda];
        Y[jy_0] += tmp1_0 * Aij_0;
        tmp2_0 += Aij_0 * X[jx_0];
        jx_0 += incX;
        jy_0 += incY;
    }

    if (i + 1 < N) {
        for (j = i + 2; j < j_max_1; j++) {
            float Aij_1 = A[(j - (i + 1)) + (i + 1) * lda];
            Y[jy_1] += tmp1_1 * Aij_1;
            tmp2_1 += Aij_1 * X[jx_1];
            jx_1 += incX;
            jy_1 += incY;
        }
        Y[iy + incY] += alpha * tmp2_1;
    }

    Y[iy] += alpha * tmp2_0;
    ix += 2 * incX;
    iy += 2 * incY;
}
}
