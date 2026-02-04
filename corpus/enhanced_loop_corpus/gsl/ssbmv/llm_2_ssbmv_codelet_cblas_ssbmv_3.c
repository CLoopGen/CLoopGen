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
for (i = 0; i < N; i++) {
    float tmp1 = alpha * X[ix];
    float tmp2 = 0.;
    const int j_min = (i > K) ? i - K : 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    float temp_A_vals[K+1];
    float temp_X_vals[K+1];
    int idx = 0;
    for (j = j_min; j < j_max; j++) {
        temp_A_vals[idx] = A[(K - i + j) + i * lda];
        temp_X_vals[idx] = X[jx];
        Y[jy] += tmp1 * temp_A_vals[idx];
        tmp2 += temp_A_vals[idx] * temp_X_vals[idx];
        jx += incX;
        jy += incY;
        idx++;
    }
    Y[iy] += tmp1 * A[K + i * lda] + alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
