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
    // Variant 2: Indirect Memory Access Pattern via Pointer Array
    // Use an array of pointers to enable indirect access, simulating irregular strides or gather pattern
    uint8_t **srcPtrs = (uint8_t**)alloca(13 * sizeof(uint8_t*));
    for (i = 0; i < w; i++) {
        // Set up base pointers for offsets from -2 to 10
        for (int j = -2; j <= 10; j++) {
            srcPtrs[j + 2] = &src[j * srcStride];
        }
        // Perform computation using indirect access through pointer array
        const int srcB = *srcPtrs[0];
        const int srcA = *srcPtrs[1];
        const int src0 = *srcPtrs[2];
        const int src1 = *srcPtrs[3];
        const int src2 = *srcPtrs[4];
        const int src3 = *srcPtrs[5];
        const int src4 = *srcPtrs[6];
        const int src5 = *srcPtrs[7];
        const int src6 = *srcPtrs[8];
        const int src7 = *srcPtrs[9];
        const int src8 = *srcPtrs[10];
        const int src9 = *srcPtrs[11];
        const int src10 = *srcPtrs[12];

        dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-1 * srcB + -2 * srcA + 96 * src0 + 42 * src1 + -7 * src2 + 0 * src3) + 64) >> 7] + 1) >> 1;
        dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * srcA + -2 * src0 + 96 * src1 + 42 * src2 + -7 * src3 + 0 * src4) + 64) >> 7] + 1) >> 1;
        dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((-1 * src0 + -2 * src1 + 96 * src2 + 42 * src3 + -7 * src4 + 0 * src5) + 64) >> 7] + 1) >> 1;
        dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((-1 * src1 + -2 * src2 + 96 * src3 + 42 * src4 + -7 * src5 + 0 * src6) + 64) >> 7] + 1) >> 1;
        dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((-1 * src2 + -2 * src3 + 96 * src4 + 42 * src5 + -7 * src6 + 0 * src7) + 64) >> 7] + 1) >> 1;
        dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((-1 * src3 + -2 * src4 + 96 * src5 + 42 * src6 + -7 * src7 + 0 * src8) + 64) >> 7] + 1) >> 1;
        dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((-1 * src4 + -2 * src5 + 96 * src6 + 42 * src7 + -7 * src8 + 0 * src9) + 64) >> 7] + 1) >> 1;
        dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((-1 * src5 + -2 * src6 + 96 * src7 + 42 * src8 + -7 * src9 + 0 * src10) + 64) >> 7] + 1) >> 1;

        dst++;
        src++;
    }
}
