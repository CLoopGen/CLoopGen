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
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j <= i; j += 2) {
        if (j + 1 <= i) {
            A[lda * i + j] += tmp1 * Y[jy] + tmp2 * X[jx];
            A[lda * i + j + 1] += tmp1 * Y[jy + incY] + tmp2 * X[jx + incX];
            jx += 2 * incX;
            jy += 2 * incY;
        } else {
            A[lda * i + j] += tmp1 * Y[jy] + tmp2 * X[jx];
        }
    }
    ix += incX;
    iy += incY;
}
}
