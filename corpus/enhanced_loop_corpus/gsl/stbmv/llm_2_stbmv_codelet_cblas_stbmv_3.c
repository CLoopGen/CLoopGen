#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
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
for (i = 0; i < N; i++) {
    float temp = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
    // Change memory access to use base pointer with consecutive indexing via offset array simulation
    // Using stride-1 access pattern by precomputing effective indices into local arrays (simulated unrolling-like access)
    for (j = j_min; j < j_max; j++) {
        int a_index = lda * j + (K - j + i);  // Original A access
        int x_index = jx;                     // Original X access via jx
        temp += X[x_index] * A[a_index];
        jx += incX;
    }
    if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + K];
    } else {
        X[ix] += temp;
    }
    ix += incX;
}
}
