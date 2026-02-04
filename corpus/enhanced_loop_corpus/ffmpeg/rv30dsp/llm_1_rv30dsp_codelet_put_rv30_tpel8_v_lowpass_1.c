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
    // Reduce effective loop depth by unrolling outer loop once and simplifying control flow
    // Simulate partial unroll: process two iterations per loop step if possible
    int limit = w;
    for (i = 0; i < limit; i += 2) {
        // First iteration of original loop
        {
            const int srcA = src[-1 * srcStride];
            const int src0 = src[0 * srcStride];
            const int src1 = src[1 * srcStride];
            const int src2 = src[2 * srcStride];
            const int src3 = src[3 * srcStride];
            const int src4 = src[4 * srcStride];
            const int src5 = src[5 * srcStride];
            const int src6 = src[6 * srcStride];
            const int src7 = src[7 * srcStride];
            const int src8 = src[8 * srcStride];
            const int src9 = src[9 * srcStride];

            dst[0 * dstStride] = cm[(-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4];
            dst[1 * dstStride] = cm[(-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4];
            dst[2 * dstStride] = cm[(-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4];
            dst[3 * dstStride] = cm[(-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4];
            dst[4 * dstStride] = cm[(-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4];
            dst[5 * dstStride] = cm[(-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4];
            dst[6 * dstStride] = cm[(-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4];
            dst[7 * dstStride] = cm[(-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4];

            dst++;
            src++;
        }

        // Second iteration, if within bounds
        if (i + 1 < w) {
            const int srcA = src[-1 * srcStride];
            const int src0 = src[0 * srcStride];
            const int src1 = src[1 * srcStride];
            const int src2 = src[2 * srcStride];
            const int src3 = src[3 * srcStride];
            const int src4 = src[4 * srcStride];
            const int src5 = src[5 * srcStride];
            const int src6 = src[6 * srcStride];
            const int src7 = src[7 * srcStride];
            const int src8 = src[8 * srcStride];
            const int src9 = src[9 * srcStride];

            dst[0 * dstStride] = cm[(-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4];
            dst[1 * dstStride] = cm[(-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4];
            dst[2 * dstStride] = cm[(-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4];
            dst[3 * dstStride] = cm[(-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4];
            dst[4 * dstStride] = cm[(-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4];
            dst[5 * dstStride] = cm[(-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4];
            dst[6 * dstStride] = cm[(-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4];
            dst[7 * dstStride] = cm[(-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4];

            dst++;
            src++;
        }
    }
}
