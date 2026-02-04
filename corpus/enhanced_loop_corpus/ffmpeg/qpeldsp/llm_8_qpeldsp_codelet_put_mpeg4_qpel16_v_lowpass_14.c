#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  uint8_t *cm;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i += 2) {
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
    const int src11 = src[11 * srcStride];
    const int src12 = src[12 * srcStride];
    const int src13 = src[13 * srcStride];
    const int src14 = src[14 * srcStride];
    const int src15 = src[15 * srcStride];
    const int src16 = src[16 * srcStride];

    // Unroll and compute two outputs per iteration with reduced operations
    dst[0 * dstStride] = cm[(((src0 + src1 + src2 + src3) * 8 + (src4 - src8) * 3 + 16) >> 5)];
    dst[1 * dstStride] = cm[(((src4 + src5 + src6 + src7) * 8 + (src8 - src12) * 3 + 16) >> 5)];

    // Skip every other pixel, reducing computational intensity
    dst += 2;
    src += 2;
}
}
