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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M; i += 2) {
    int ix1 = ix;
    int ix2 = ix + incX;
    const double tmp1 = alpha * X[ix1];
    const double tmp2 = (i + 1 < M) ? alpha * X[ix2] : 0.0;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        A[lda * i + j] += Y[jy] * tmp1;
        if (i + 1 < M) {
            A[lda * (i + 1) + j] += Y[jy] * tmp2;
        }
        jy += incY;
    }
    ix += 2 * incX;
}
}
