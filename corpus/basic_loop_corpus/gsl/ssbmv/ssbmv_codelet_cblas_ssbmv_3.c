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
    for (j = j_min; j < j_max; j++) {
        float Aij = A[(K - i + j) + i * lda];
        Y[jy] += tmp1 * Aij;
        tmp2 += Aij * X[jx];
        jx += incX;
        jy += incY;
    }
    Y[iy] += tmp1 * A[K + i * lda] + alpha * tmp2;
    ix += incX;
    iy += incY;
}

}
