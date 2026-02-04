#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
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
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j += 2) {
    const double tmp0 = alpha * Y[jy];
    const double tmp1 = (j + 1 < N) ? alpha * Y[jy + incY] : 0.0;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        A[i + lda * j] += X[ix] * tmp0;
        if (j + 1 < N) {
            A[i + lda * (j + 1)] += X[ix] * tmp1;
        }
        ix += incX;
    }
    jy += 2 * incY;
}
}
