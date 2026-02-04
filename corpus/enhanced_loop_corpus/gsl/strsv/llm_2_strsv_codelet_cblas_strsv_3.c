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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access via ix and jx, we use direct indexing with consecutive strides precomputed.
    // This improves cache locality by accessing X in increasing index order (forward traversal).
    float *X_base = X;
    const int stride = incX;
    for (i = N - 1; i > 0 && i--;) {
        int idx_i = i * stride;
        float tmp = X_base[idx_i];
        int jx_idx = (i + 1) * stride;
        for (j = i + 1; j < N; j++) {
            const float Aji = A[lda * j + i];
            tmp -= Aji * X_base[jx_idx];
            jx_idx += stride;
        }
        if (nonunit) {
            X_base[idx_i] = tmp / A[lda * i + i];
        } else {
            X_base[idx_i] = tmp;
        }
    }
}
