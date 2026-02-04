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
extern  int nonunit;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) { // Process two iterations at once, unrolled loop
    if (i + 1 >= N) {
        // Handle odd N: fall back to single iteration for last element
        float tmp = X[ix];
        const int j_min = (i > K ? i - K : 0);
        const int j_max = i;
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min * incX;
        for (j = j_min; j < j_max; j++) {
            const float Aij = A[lda * i + (K + j - i)];
            tmp -= Aij * X[jx];
            jx += incX;
        }
        if (nonunit) {
            X[ix] = tmp / A[lda * i + K];
        } else {
            X[ix] = tmp;
        }
        ix += incX;
        break;
    }

    // Unroll two iterations
    float tmp1 = X[ix];
    float tmp2 = X[ix + incX];
    const int j_min1 = (i > K ? i - K : 0);
    const int j_min2 = (i+1 > K ? i+1 - K : 0);
    const int j_max1 = i;
    const int j_max2 = i+1;

    int jx1 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min1 * incX;
    int jx2 = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + j_min2 * incX;

    // Process j from max(j_min1, j_min2) to j_max1 (common segment)
    int j_start = (j_min1 < j_min2) ? j_min2 : j_min1;
    for (j = j_start; j < j_max1; j++) {
        const float Aij1 = A[lda * i + (K + j - i)];
        const float Aij2 = A[lda * (i+1) + (K + j - (i+1))];
        tmp1 -= Aij1 * X[jx1 + (j - j_min1) * incX];
        tmp2 -= Aij2 * X[jx2 + (j - j_min2) * incX];
    }

    // Handle remaining j for second row if needed
    for (; j < j_max2; j++) {
        const float Aij2 = A[lda * (i+1) + (K + j - (i+1))];
        tmp2 -= Aij2 * X[jx2 + (j - j_min2) * incX];
    }

    // Finalize first update
    if (nonunit) {
        X[ix] = tmp1 / A[lda * i + K];
    } else {
        X[ix] = tmp1;
    }
    ix += incX;

    // Finalize second update
    if (nonunit) {
        X[ix] = tmp2 / A[lda * (i+1) + K];
    } else {
        X[ix] = tmp2;
    }
    ix += incX;
}
}
