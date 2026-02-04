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
for (i = N; i > 0 && i--;) {
    double temp = 0.;
    const int j_min = (K > i ? 0 : i - K);
    const int j_max = i;
    // Use indirect array indexing via index arrays to simulate indirect memory access pattern
    // Assuming auxiliary index arrays are available: precomputed_jx[N], precomputed_A_idx[N]
    // Simulate indirect access without external declarations by computing indices into local arrays
    for (j = j_min; j < j_max; j++) {
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j * incX;
        int a_index = lda * j + (i - j);
        temp += X[jx] * A[a_index];
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + 0];
    } else {
        X[ix] += temp;
    }
    ix -= incX;
}
}
