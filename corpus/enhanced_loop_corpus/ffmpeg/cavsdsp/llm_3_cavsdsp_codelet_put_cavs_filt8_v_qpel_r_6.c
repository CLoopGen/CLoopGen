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
    // Variant 2: Strided memory access with precomputed source indices
    ptrdiff_t s = srcStride;
    ptrdiff_t d = dstStride;

    // Precompute offsets to enable strided access pattern
    const ptrdiff_t srcOffsets[] = {
        -2*s, -1*s, 0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s, 10*s
    };

    for (i = 0; i < w; i++) {
        const int srcB = src[srcOffsets[0]];
        const int srcA = src[srcOffsets[1]];
        const int src0 = src[srcOffsets[2]];
        const int src1 = src[srcOffsets[3]];
        const int src2 = src[srcOffsets[4]];
        const int src3 = src[srcOffsets[5]];
        const int src4 = src[srcOffsets[6]];
        const int src5 = src[srcOffsets[7]];
        const int src6 = src[srcOffsets[8]];
        const int src7 = src[srcOffsets[9]];
        const int src8 = src[srcOffsets[10]];
        const int src9 = src[srcOffsets[11]];
        const int src10 = src[srcOffsets[12]];

        // Use strided writes via offset table
        const ptrdiff_t dstOffsets[] = {0*d, 1*d, 2*d, 3*d, 4*d, 5*d, 6*d, 7*d};

        dst[dstOffsets[0]] = cm[((0 * srcB + -7 * srcA + 42 * src0 + 96 * src1 + -2 * src2 + -1 * src3) + 64) >> 7];
        dst[dstOffsets[1]] = cm[((0 * srcA + -7 * src0 + 42 * src1 + 96 * src2 + -2 * src3 + -1 * src4) + 64) >> 7];
        dst[dstOffsets[2]] = cm[((0 * src0 + -7 * src1 + 42 * src2 + 96 * src3 + -2 * src4 + -1 * src5) + 64) >> 7];
        dst[dstOffsets[3]] = cm[((0 * src1 + -7 * src2 + 42 * src3 + 96 * src4 + -2 * src5 + -1 * src6) + 64) >> 7];
        dst[dstOffsets[4]] = cm[((0 * src2 + -7 * src3 + 42 * src4 + 96 * src5 + -2 * src6 + -1 * src7) + 64) >> 7];
        dst[dstOffsets[5]] = cm[((0 * src3 + -7 * src4 + 42 * src5 + 96 * src6 + -2 * src7 + -1 * src8) + 64) >> 7];
        dst[dstOffsets[6]] = cm[((0 * src4 + -7 * src5 + 42 * src6 + 96 * src7 + -2 * src8 + -1 * src9) + 64) >> 7];
        dst[dstOffsets[7]] = cm[((0 * src5 + -7 * src6 + 42 * src7 + 96 * src8 + -2 * src9 + -1 * src10) + 64) >> 7];

        dst += 1;
        src += 1;
    }
}
