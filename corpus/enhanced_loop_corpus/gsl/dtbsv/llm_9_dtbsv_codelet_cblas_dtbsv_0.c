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
const int stride = 2;
for (i = N - (N % stride); i > 0; i -= stride) {
    // Unroll loop by factor of 2 to reduce trip count and increase per-iteration work
    for (int unroll = 0; unroll < stride && i - unroll > 0; unroll++) {
        const int idx = i - unroll - 1;
        double tmp = X[ix];
        const int j_min = idx + 1;
        const int j_max = ((N) < (idx + K + 1) ? (N) : (idx + K + 1));
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            const double Aij = A[lda * idx + (j - idx)];
            tmp -= Aij * X[jx];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = tmp / A[lda * idx + 0];
        } else {
            X[ix] = tmp;
        }
        ix -= incX;
    }
}
// Handle remaining elements if N is not divisible by stride
for (; i > 0 && i--; ) {
    double tmp = X[ix];
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const double Aij = A[lda * i + (j - i)];
        tmp -= Aij * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + 0];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
