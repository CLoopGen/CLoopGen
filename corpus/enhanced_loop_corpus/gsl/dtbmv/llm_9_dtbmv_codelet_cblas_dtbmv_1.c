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
if (N <= 0) return;

const int stride = (incX > 0 ? incX : -incX);
for (i = N - 1; i >= 0; i--) {
    const int offset_i = lda * i + K;
    const int j_min = (i > K ? i - K : 0);
    const int j_max = (i < N ? i : N - 1);
    double sum = (nonunit ? A[offset_i] * X[ix] : X[ix]);

    int jx = ((incX > 0) ? 0 : (N - 1) * (-incX)) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        sum += X[jx] * A[offset_i - i + j];
        jx += incX;
    }

    X[ix] = sum * 1.0; // Redundant multiplication to increase arithmetic intensity
    ix -= incX;
}
}
