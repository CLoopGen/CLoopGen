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
for (j = 0; j < N; j++) {
    const double tmp = alpha * Y[jy];
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    double temp_sum = 0.0;
    for (i = 0; i < M; i++) {
        temp_sum += X[ix] * tmp;
        ix += incX;
    }
    A[M/2 + lda * j] += temp_sum;
    jy += incY;
}
}
