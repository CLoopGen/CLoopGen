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
for (i = 0; i < N; i++) {
    double temp = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    // Change memory access to use consecutive indexing by precomputing base offsets
    const ptrdiff_t a_base = lda * j_min + (K - j_min + i);
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[a_base + (j - j_min) + (ptrdiff_t)(lda * (j - j_min))];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + K];
    } else {
        X[ix] += temp;
    }
    ix += incX;
}
}
