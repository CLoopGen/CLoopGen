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
if (N <= 1) return;
float sum = 0.0f;
jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
for (i = 1; i < N; i++) {
    for (j = 0; j < i; j++) {
        sum += A[lda * j + i] * X[jx];
        jx += incX;
    }
    jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))); // Reset jx
}
// Final update using accumulated sum
if (nonunit && A[lda * (N-1) + (N-1)] != 0.0f) {
    X[ix] = (X[ix] - sum) / A[lda * (N-1) + (N-1)];
} else {
    X[ix] = X[ix] - sum;
}
ix += incX * (N - 1); // Advance pointer to simulate full traversal
}
