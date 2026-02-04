#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Precomputed Index Arrays (simulate gather-like access)
    ptrdiff_t srcIndices[11];
    ptrdiff_t dstIndices[8];

    for (i = 0; i < w; i++) {
        // Precompute source indices using indirect addressing pattern
        for (int j = -2; j <= 10; j++) {
            srcIndices[j + 2] = (i + j) * srcStride;
        }

        // Precompute destination indices for output write
        for (int k = 0; k < 8; k++) {
            dstIndices[k] = (i + k) * dstStride;
        }

        const int srcB = src[srcIndices[0]];
        const int srcA = src[srcIndices[1]];
        const int src0 = src[srcIndices[2]];
        const int src1 = src[srcIndices[3]];
        const int src2 = src[srcIndices[4]];
        const int src3 = src[srcIndices[5]];
        const int src4 = src[srcIndices[6]];
        const int src5 = src[srcIndices[7]];
        const int src6 = src[srcIndices[8]];
        const int src7 = src[srcIndices[9]];
        const int src8 = src[srcIndices[10]];
        const int src9 = src[srcIndices[11]];
        const int src10 = src[srcIndices[12]];

        dst[dstIndices[0]] = cm[((-1 * srcB + -2 * srcA + 96 * src0 + 42 * src1 + -7 * src2 + 0 * src3) + 64) >> 7];
        dst[dstIndices[1]] = cm[((-1 * srcA + -2 * src0 + 96 * src1 + 42 * src2 + -7 * src3 + 0 * src4) + 64) >> 7];
        dst[dstIndices[2]] = cm[((-1 * src0 + -2 * src1 + 96 * src2 + 42 * src3 + -7 * src4 + 0 * src5) + 64) >> 7];
        dst[dstIndices[3]] = cm[((-1 * src1 + -2 * src2 + 96 * src3 + 42 * src4 + -7 * src5 + 0 * src6) + 64) >> 7];
        dst[dstIndices[4]] = cm[((-1 * src2 + -2 * src3 + 96 * src4 + 42 * src5 + -7 * src6 + 0 * src7) + 64) >> 7];
        dst[dstIndices[5]] = cm[((-1 * src3 + -2 * src4 + 96 * src5 + 42 * src6 + -7 * src7 + 0 * src8) + 64) >> 7];
        dst[dstIndices[6]] = cm[((-1 * src4 + -2 * src5 + 96 * src6 + 42 * src7 + -7 * src8 + 0 * src9) + 64) >> 7];
        dst[dstIndices[7]] = cm[((-1 * src5 + -2 * src6 + 96 * src7 + 42 * src8 + -7 * src9 + 0 * src10) + 64) >> 7];
    }
}
