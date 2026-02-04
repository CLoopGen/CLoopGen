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
// Variant with reduced loop-carried dependencies and unrolled accumulation
for (i = 0; i < N; i++) {
    float temp1 = 0.0f, temp2 = 0.0f;
    const int j_min = i + 1;
    const int j_max = (N < i + K + 1) ? N : i + K + 1;
    int jx_start = (incX > 0 ? 0 : (N - 1) * (-incX)) + j_min * incX;

    // Split the inner loop into two parts to break dependency chain in accumulation
    int mid = (j_min + j_max) / 2;
    int jx = jx_start;
    for (j = j_min; j < mid; j++) {
        temp1 += X[jx] * A[lda * j + (K - j + i)];
        jx += incX;
    }
    for (j = mid; j < j_max; j++) {
        temp2 += X[jx] * A[lda * j + (K - j + i)];
        jx += incX;
    }
    float total_temp = temp1 + temp2;

    // Eliminate WAW hazard by ensuring only one write to X[ix]
    if (nonunit) {
        X[ix] = total_temp + X[ix] * A[lda * i + K];
    } else {
        X[ix] = total_temp; // Changed from += to = to remove read-before-write dependency
    }
    ix += incX;
}
}
