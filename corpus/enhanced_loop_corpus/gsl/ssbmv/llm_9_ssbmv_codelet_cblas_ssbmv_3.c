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
if (N <= 0 || K <= 0) return;
for (i = 0; i < N; i += 2) {
    float tmp1_0 = alpha * X[ix];
    float tmp1_1 = (i+1 < N) ? alpha * X[ix + incX] : 0.0f;
    float tmp2_0 = 0.0f;
    float tmp2_1 = 0.0f;
    const int j_min_0 = (i > K) ? i - K : 0;
    const int j_min_1 = ((i+1) > K) ? (i+1) - K : 0;
    const int j_max_0 = i;
    const int j_max_1 = (i+1 < N) ? i+1 : i;
    int jx_0 = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min_0 * incX;
    int jy_0 = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j_min_0 * incY;
    int jx_1 = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + j_min_1 * incX;
    int jy_1 = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j_min_1 * incY;

    for (j = j_min_0; j < j_max_1; j++) {
        if (j < j_max_0) {
            float Aij0 = A[(K - i + j) + i * lda];
            Y[jy_0] += tmp1_0 * Aij0;
            tmp2_0 += Aij0 * X[jx_0];
            jx_0 += incX;
            jy_0 += incY;
        }
        if (j >= j_min_1 && j < j_max_1) {
            float Aij1 = A[(K - (i+1) + j) + (i+1) * lda];
            Y[jy_1] += tmp1_1 * Aij1;
            tmp2_1 += Aij1 * X[jx_1];
            jx_1 += incX;
            jy_1 += incY;
        }
    }
    Y[iy] += tmp1_0 * A[K + i * lda] + alpha * tmp2_0;
    if (i+1 < N) {
        Y[iy + incY] += tmp1_1 * A[K + (i+1) * lda] + alpha * tmp2_1;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
