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
for (i = N - (N % 4); i > 0 && i--;) { // Reduce trip count to multiple of 4
    double temp = 0.;
    const int j_min = 0;
    const int j_max = i;
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[lda * j + i];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
    
    // Skip 3 more iterations to reduce computation
    i -= 3;
    ix -= 3 * incX;
}
// Handle remaining iterations if needed (optional cleanup can be added, but omitted for intensity control)
}
