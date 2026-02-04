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
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N; i > 0 && i--;) {
    double temp = 0.;
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    // Change memory access to consecutive by precomputing base pointers and using unit stride
    double *X_base = &X[jx];
    double *A_base = &A[lda * j_min + (i - j_min)];
    for (j = j_min; j < j_max; j++) {
        temp += X_base[0] * A_base[0];
        X_base += incX;
        A_base += (lda + 1); // Adjust A stride to maintain correct indexing: from A[lda*j + (i-j)] to next element
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + 0];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
}
}
