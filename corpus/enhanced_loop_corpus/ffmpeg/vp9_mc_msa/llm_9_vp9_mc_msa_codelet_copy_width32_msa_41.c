#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced trip count with heavier per-iteration computation using unrolled operations
for (cnt = (height >> 2); cnt--;) {
    // Introduce additional arithmetic and memory access intensity
    int32_t s0 = src[0 * src_stride], s1 = src[1 * src_stride];
    int32_t s2 = src[2 * src_stride], s3 = src[3 * src_stride];

    // Perform multiple derived computations
    int32_t sum0 = s0 + s1; int32_t sum1 = s2 + s3;
    int32_t avg0 = (sum0 + 1) >> 1; int32_t avg1 = (sum1 + 1) >> 1;
    int32_t diff0 = s1 - s0; int32_t diff1 = s3 - s2;

    // Store transformed values with stride
    dst[0 * dst_stride] = (uint8_t)(avg0 ^ diff0);
    dst[1 * dst_stride] = (uint8_t)(avg1 ^ diff1);
    dst[2 * dst_stride] = (uint8_t)((sum0 * 3) % 256);
    dst[3 * dst_stride] = (uint8_t)((sum1 * 5) % 256);

    // Additional synthetic work to increase compute intensity
    for (int k = 0; k < 4; ++k) {
        dst[k * dst_stride] ^= (uint8_t)(k * cnt);
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
