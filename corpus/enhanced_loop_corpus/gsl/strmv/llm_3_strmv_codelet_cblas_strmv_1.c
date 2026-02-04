#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N; i > 0 && i--;) {
    float temp = 0.;
    const int j_min = 0;
    const int j_max = i;
    // Use indirect array indexing via an index array to simulate indirect memory access
    // Simulate index vector without external storage by computing on-the-fly
    for (j = j_min; j < j_max; j++) {
        int indirect_jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j * incX; // Computed index mimics indirect access
        temp += X[indirect_jx] * A[lda * i + j];
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
}
}
