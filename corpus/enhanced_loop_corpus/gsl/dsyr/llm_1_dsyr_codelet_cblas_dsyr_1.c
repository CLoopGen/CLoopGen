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
        double temp_accum = X[jx] * tmp;
        int k;
        for (k = 0; k < 1; k++) {
            A[lda * i + j] += temp_accum;
        }
        jx += incX;
    }
    ix += incX;
}
}
