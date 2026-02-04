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
if (N <= 0) return;
// Unroll the outer loop by a factor of 2 to reduce trip count and increase per-iteration work
for (i = N - 1; i >= 1; ) {
    // First iteration of unrolled pair
    double tmp = X[ix];
    jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const double Aji = A[lda * j + i];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * i + i];
    } else {
        X[ix] = tmp;
    }
    int prev_ix = ix;
    ix -= incX;
    i--;

    // Second iteration (check bounds)
    if (i <= 0) break;

    double tmp2 = X[ix];
    jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const double Aji = A[lda * j + i];
        tmp2 -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp2 / A[lda * i + i];
    } else {
        X[ix] = tmp2;
    }
    ix -= incX;
    i--;
}
}
