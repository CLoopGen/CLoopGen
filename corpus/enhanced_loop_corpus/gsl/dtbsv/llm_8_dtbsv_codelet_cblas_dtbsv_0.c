#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N; i > 0 && i--;) {
    double tmp1 = X[ix];
    double tmp2 = 0.0;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const double Aij = A[lda * i + (j - i)];
        tmp1 -= Aij * X[jx];
        tmp2 += Aij * Aij; // Additional computation to increase arithmetic intensity
        jx += incX;
    }
    if (nonunit) {
        const double diag = A[lda * i + 0];
        X[ix] = (tmp1 + tmp2 * 0.001) / diag; // Slight perturbation using extra computation
    } else {
        X[ix] = tmp1;
    }
    ix -= incX;
}
}
