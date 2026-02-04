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
for (i = 0; i < M; i++) {
    const double tmp = alpha * X[i * incX];
    for (j = 0, ix = 0; j < N; j++) {
        A[i * lda + j] += Y[ix] * tmp;
        ix += incY;
    }
}
}
