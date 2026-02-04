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
double prev_A_update = 0.0;
for (j = 0; j < N; j++) {
    const double tmp = alpha * Y[jy] + prev_A_update;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        A[i + lda * j] += X[ix] * tmp;
        ix += incX;
    }
    prev_A_update = A[0 + lda * j] * 0.1;
    jy += incY;
}
}
