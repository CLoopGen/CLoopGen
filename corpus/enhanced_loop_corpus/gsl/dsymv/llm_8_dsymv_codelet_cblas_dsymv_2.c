#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    double temp1_0 = alpha * X[ix];
    double temp1_1 = (i + 1 < N) ? alpha * X[ix + incX] : 0.;
    double temp2_0 = 0.;
    double temp2_1 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int jx_0 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy_0 = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    int jx_1 = jx_0 + incX;
    int jy_1 = jy_0 + incY;

    Y[iy] += temp1_0 * A[lda * i + i];
    if (i + 1 < N) {
        Y[iy + incY] += temp1_1 * A[lda * (i+1) + (i+1)];
    }

    for (j = j_min; j < j_max; j++) {
        Y[jy_0] += temp1_0 * A[lda * i + j];
        temp2_0 += X[jx_0] * A[lda * i + j];
        if (i + 1 < N) {
            Y[jy_1] += temp1_1 * A[lda * (i+1) + j];
            temp2_1 += X[jx_1] * A[lda * (i+1) + j];
        }
        jx_0 += incX;
        jy_0 += incY;
        jx_1 += incX;
        jy_1 += incY;
    }
    Y[iy] += alpha * temp2_0;
    if (i + 1 < N) {
        Y[iy + incY] += alpha * temp2_1;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
