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
for (i = 0; i < N; i++) {
    double tmp = X[ix];
    const int j_min = (i > K ? i - K : 0);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    // Change memory access to use a strided pattern with explicit stride handling
    for (j = j_min; j < j_max; j++) {
        const int a_index = lda * i + (K + j - i); // Strided access in A due to lda
        tmp -= A[a_index] * X[jx];
        jx += incX;
    }
    if (nonunit) {
        const int diag_index = lda * i + K;
        X[ix] = tmp / A[diag_index];
    } else {
        X[ix] = tmp;
    }
    ix += incX;
}
}
