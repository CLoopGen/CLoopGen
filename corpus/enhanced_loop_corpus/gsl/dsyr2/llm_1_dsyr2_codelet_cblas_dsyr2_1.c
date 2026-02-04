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
if (N <= 0) return;
const int start_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));
const int start_iy = ((incY) > 0 ? 0 : (N - 1) * (-incY));
for (i = 0; i < N; i++) {
    const int current_ix = start_ix + i * incX;
    const int current_iy = start_iy + i * incY;
    const double tmp1 = alpha * X[current_ix];
    const double tmp2 = alpha * Y[current_iy];
    int jx = start_ix;
    int jy = start_iy;
    for (j = 0; j <= i; j++) {
        A[lda * i + j] += tmp1 * Y[jy] + tmp2 * X[jx];
        jx += incX;
        jy += incY;
    }
}
ix = start_ix + N * incX;
iy = start_iy + N * incY;
}
