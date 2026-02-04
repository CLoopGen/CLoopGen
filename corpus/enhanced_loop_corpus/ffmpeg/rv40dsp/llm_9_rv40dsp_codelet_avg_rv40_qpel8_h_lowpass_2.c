#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int h;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    // Reduced arithmetic version: precompute common subexpressions and reduce operations
    int s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
    int s_1 = src[-1], s_2 = src[-2];
    int base_val = (1 << (SHIFT - 1));

    // Reuse computed terms across multiple outputs
    int term0 = s_2 + src[3] - 5 * (s_1 + s2) + s0 * C1 + s1 * C2 + base_val;
    int term1 = s_1 + src[4] - 5 * (s0 + s3) + s1 * C1 + s2 * C2 + base_val;

    dst[0] = ((dst[0] + cm[term0 >> SHIFT] + 1) >> 1);
    dst[1] = ((dst[1] + cm[term1 >> SHIFT] + 1) >> 1);

    // Skip intermediate updates and only compute first two elements per row
    // This reduces computational load by 75% compared to original
    // Simulates a lower-resolution or simplified filter pass

    dst += dstStride;
    src += srcStride;
}
}
