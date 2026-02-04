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
for (i = N; i > 0 && i--;) {
    double temp1 = 0., temp2 = 0.;
    const int j_min = 0;
    const int j_max = i - (i % 2); // Make even for pairing
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j += 2) {
        temp1 += X[jx] * A[lda * j + i];
        temp2 += X[jx + incX] * A[lda * (j + 1) + i];
        jx += 2 * incX;
    }
    // Handle leftover if j_max was adjusted
    if (j == i - 1) {
        temp1 += X[jx] * A[lda * j + i];
    }
    temp1 += temp2;
    if (nonunit) {
        X[ix] = temp1 + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp1;
    }
    ix -= incX;
}
}
