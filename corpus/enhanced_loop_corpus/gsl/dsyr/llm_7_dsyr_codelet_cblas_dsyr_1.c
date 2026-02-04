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
double temp_accum = 0.0;
for (i = 0; i < N; i++) {
    const double tmp = alpha * X[ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    temp_accum = 0.0;
    for (j = 0; j <= i; j++) {
        temp_accum += X[jx];
        jx += incX;
    }
    A[lda * i + i] = temp_accum * tmp;
    ix += incX;
}
}
