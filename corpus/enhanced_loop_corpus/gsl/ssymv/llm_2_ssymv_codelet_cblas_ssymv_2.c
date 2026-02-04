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
for (i = 0; i < N; i++) {
    float temp1 = alpha * X[ix];
    float temp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    Y[iy] += temp1 * A[lda * i + i];
    for (j = j_min; j < j_max; j++) {
        Y[jy] += temp1 * A[lda * i + j];
        temp2 += X[jx] * A[lda * i + j];
        jx += incX;
        jy += incY;
    }
    Y[iy] += alpha * temp2;
    ix += incX;
    iy += incY;
}
}
