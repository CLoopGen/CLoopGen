#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
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
    const int j_max = (N / 2); // Reduced trip count in inner loop
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[lda * i + j];
        jx += incX;
    }
    // Additional scalar operations to increase computational intensity
    temp *= 1.5;
    temp += 0.1 * temp * temp;
    if (nonunit && A[lda * i + i] != 0.0) {
        X[ix] = (temp + X[ix]) * A[lda * i + i];
    } else {
        X[ix] = temp + X[ix] * 0.9;
    }
    ix += incX;
}
}
