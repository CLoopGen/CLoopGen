#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i += 2) {
    const int srcB = src[-2 * srcStride];
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
    const int src10 = src[10 * srcStride];

    // Process two output pixels per iteration with reduced memory access frequency
    dst[0 * dstStride] = cm[(srcB + src3 - 5 * (srcA + src2) + src0 * C1 + src1 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[1 * dstStride] = cm[(srcA + src4 - 5 * (src0 + src3) + src1 * C1 + src2 * C2 + (1 << (SHIFT - 1))) >> SHIFT];

    // Reuse shifted values for second group
    dst[2 * dstStride] = cm[(src0 + src5 - 5 * (src1 + src4) + src2 * C1 + src3 * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[3 * dstStride] = cm[(src1 + src6 - 5 * (src2 + src5) + src3 * C1 + src4 * C2 + (1 << (SHIFT - 1))) >> SHIFT];

    dst += 2;
    src += 2;
}
}
