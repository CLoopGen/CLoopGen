#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching and Loop Unrolling
    // Instead of strided access, we pre-load a block of src values into a local array to enable consecutive access pattern.
    // This improves cache locality and enables better vectorization.

    uint8_t src_cache[11]; // Local cache to hold the sliding window of src values

    for (i = 0; i < w; i++) {
        // Load 11 elements centered around current src position to cover [-1..9] range
        for (int j = -1; j <= 9; j++) {
            src_cache[j + 1] = src[j * srcStride];
        }

        const int srcA = src_cache[0];
        const int src0 = src_cache[1];
        const int src1 = src_cache[2];
        const int src2 = src_cache[3];
        const int src3 = src_cache[4];
        const int src4 = src_cache[5];
        const int src5 = src_cache[6];
        const int src6 = src_cache[7];
        const int src7 = src_cache[8];
        const int src8 = src_cache[9];
        const int src9 = src_cache[10];

        dst[0 * dstStride] = (((dst[0 * dstStride]) + cm[(-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4] + 1) >> 1);
        dst[1 * dstStride] = (((dst[1 * dstStride]) + cm[(-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4] + 1) >> 1);
        dst[2 * dstStride] = (((dst[2 * dstStride]) + cm[(-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4] + 1) >> 1);
        dst[3 * dstStride] = (((dst[3 * dstStride]) + cm[(-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4] + 1) >> 1);
        dst[4 * dstStride] = (((dst[4 * dstStride]) + cm[(-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4] + 1) >> 1);
        dst[5 * dstStride] = (((dst[5 * dstStride]) + cm[(-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4] + 1) >> 1);
        dst[6 * dstStride] = (((dst[6 * dstStride]) + cm[(-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4] + 1) >> 1);
        dst[7 * dstStride] = (((dst[7 * dstStride]) + cm[(-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4] + 1) >> 1);

        dst++;
        src++;
    }
}
