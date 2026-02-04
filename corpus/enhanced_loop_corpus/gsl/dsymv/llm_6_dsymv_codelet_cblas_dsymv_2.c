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
for (i = 0; i < N; i++) {
    double temp1 = alpha * X[ix];
    double temp2 = 0.;
    const int j_min = i + 1;
    const int j_max = N;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY))) + j_min * incY;
    for (j = j_min; j < j_max; j++) {
        temp2 += X[jx] * A[lda * i + j];
        Y[jy] += temp1 * A[lda * i + j];
        jx += incX;
        jy += incY;
    }
    Y[iy] += temp1 * A[lda * i + i] + alpha * temp2;
    ix += incX;
    iy += incY;
}
}
