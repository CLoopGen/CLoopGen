#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *restrict local_X = X;
const double *restrict local_A = A;
int local_N = N;
int local_lda = lda;
int local_incX = incX;
int local_nonunit = nonunit;

for (i = local_N - 1; i > 0 && i--;) {
    double tmp = local_X[ix];
    jx = ix + local_incX;
    for (j = i + 1; j < local_N; j++) {
        const double Aij = local_A[local_lda * i + j];
        tmp -= Aij * local_X[jx];
        jx += local_incX;
    }
    if (local_nonunit) {
        X[ix] = tmp / local_A[local_lda * i + i];
    } else {
        X[ix] = tmp;
    }
    ix -= local_incX;
}
}
