#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *A;
extern  int lda;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double tmp = alpha * X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j <= i; j++) {
        if (j > 0 || incX > 0) {
            A[lda * i + j] += X[jx] * tmp;
        } else {
            A[lda * i + j] = A[lda * i + j] + X[jx] * tmp;
        }
        jx += incX;
    }
    ix += incX;
}
}
