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
    // Variant 2: Strided memory access (stride of 2) with dual update per iteration
    // Process two pairs per iteration with a fixed stride to promote vectorization or cache utilization
    // Adjust loop bound to handle even 'len' safely; assume len is positive and reasonably large
    int stride = 2;
    int iterations = len / stride;
    int remainder = len % stride;

    // Main loop with stride 2
    for (int k = 0; k < iterations; k++) {
        int base_i = -len + k * stride;
        int base_j = len - 1 - k * stride;

        // First pair
        float s0_0 = src0[base_i];
        float s1_0 = src1[base_j];
        float wi_0 = win[base_i];
        float wj_0 = win[base_j];
        dst[base_i] = s0_0 * wj_0 - s1_0 * wi_0;
        dst[base_j] = s0_0 * wi_0 + s1_0 * wj_0;

        // Second pair (if within bounds)
        int next_i = base_i + 1;
        int next_j = base_j - 1;
        if (k * stride + 1 < len) { // Ensure second update is valid
            float s0_1 = src0[next_i];
            float s1_1 = src1[next_j];
            float wi_1 = win[next_i];
            float wj_1 = win[next_j];
            dst[next_i] = s0_1 * wj_1 - s1_1 * wi_1;
            dst[next_j] = s0_1 * wi_1 + s1_1 * wj_1;
        }
    }

    // Handle remaining element if len is odd
    if (remainder > 0) {
        int i = -1;
        int j = 0;
        float s0 = src0[i];
        float s1 = src1[j];
        float wi = win[i];
        float wj = win[j];
        dst[i] = s0 * wj - s1 * wi;
        dst[j] = s0 * wi + s1 * wj;
    }
}
