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
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    Y[iy] += tmp1 * A[0 + i * lda];
    if (j_min < j_max) {
        for (int k = 0; k < (j_max - j_min); k++) {
            int j = j_min + k;
            float Aij = A[(j - i) + i * lda];
            Y[jy] += tmp1 * Aij;
            tmp2 += Aij * X[jx];
            jx += incX;
            jy += incY;
        }
    }
    Y[iy] += alpha * tmp2;
    ix += incX;
    iy += incY;
}
}
