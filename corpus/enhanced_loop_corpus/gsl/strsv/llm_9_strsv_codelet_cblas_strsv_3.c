#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count by processing two iterations per loop cycle (unrolling-like)
for (i = N - 1; i > 1; i -= 2) {
    // First iteration (i)
    float tmp1 = X[ix];
    jx = ix + incX;
    for (j = i + 1; j < N; j++) {
        const float Aji = A[lda * j + i];
        tmp1 -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp1 / A[lda * i + i];
    } else {
        X[ix] = tmp1;
    }

    // Second iteration (i-1), if valid
    int i_prev = i - 1;
    int ix_prev = ix - incX;
    float tmp2 = X[ix_prev];
    jx = ix_prev + incX;
    for (j = i_prev + 1; j < N; j++) {
        const float Aji = A[lda * j + i_prev];
        tmp2 -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix_prev] = tmp2 / A[lda * i_prev + i_prev];
    } else {
        X[ix_prev] = tmp2;
    }

    ix -= 2 * incX; // Advance index by two steps
}
// Handle remaining single element if N is even
if (i == 1) {
    float tmp = X[ix];
    jx = ix + incX;
    for (j = 2; j < N; j++) {
        const float Aji = A[lda * j + 1];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = tmp / A[lda * 1 + 1];
    } else {
        X[ix] = tmp;
    }
    ix -= incX;
}
}
