#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src0;
extern  float *src1;
extern  float *win;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies by unrolling two iterations and reordering operations
    // Also remove some direct data dependencies by precomputing independent expressions
    int stride = 2;
    for (i = -len, j = len - 1; i < -1; i += stride, j -= stride) {
        // Precompute all required values for both i and i+1 (if applicable) without immediate use
        float s0_i = src0[i],     s1_j = src1[j];
        float wi_i = win[i],      wj_j = win[j];
        float s0_in = src0[i+1],  s1_jn = src1[j-1];
        float wi_in = win[i+1],   wj_jn = win[j-1];

        // Reorder computations to break apparent dependencies and allow compiler optimization
        dst[j] = s0_i * wi_i + s1_j * wj_j;
        dst[i] = s0_i * wj_j - s1_j * wi_i;

        // Use next index pair immediately, no dependency on previous store
        dst[j-1] = s0_in * wi_in + s1_jn * wj_jn;
        dst[i+1] = s0_in * wj_jn - s1_jn * wi_in;
    }

    // Handle remaining single iteration if len is odd
    if (i == -1) {
        float s0 = src0[i];
        float s1 = src1[j];
        float wi = win[i];
        float wj = win[j];
        dst[i] = s0 * wj - s1 * wi;
        dst[j] = s0 * wi + s1 * wj;
    }
}
