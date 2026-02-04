#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    if (i + 1 >= N) continue;
    const double tmp1_i = alpha * X[ix];
    const double tmp2_i = alpha * Y[iy];
    const double tmp1_ip1 = alpha * X[ix + incX];
    const double tmp2_ip1 = alpha * Y[iy + incY];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j <= i + 1; j++) {
        if (j <= i) {
            A[lda * i + j] += tmp1_i * Y[jy] + tmp2_i * X[jx];
        }
        if (j <= i + 1) {
            A[lda * (i + 1) + j] += tmp1_ip1 * Y[jy] + tmp2_ip1 * X[jx];
        }
        jx += incX;
        jy += incY;
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
