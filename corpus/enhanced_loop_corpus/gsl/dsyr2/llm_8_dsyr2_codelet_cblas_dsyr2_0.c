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
    int jx = ix;
    int jy = iy;
    for (j = i; j < N; j += 2) {
        A[lda * i + j] += tmp1 * Y[jy] + tmp2 * X[jx];
        if (j + 1 < N) {
            A[lda * i + j + 1] += tmp1 * Y[jy + incY] + tmp2 * X[jx + incX];
        }
        jx += 2 * incX;
        jy += 2 * incY;
    }
    ix += incX;
    iy += incY;
}
}
