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
// Reduced computational intensity: unroll only partially and reduce arithmetic density
for (i = 0; i < w; i++) {
    // Load fewer source values per iteration
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];

    // Simplify computation: use only one weighted term and reduce offset arithmetic
    const int index = ((src0 * C1 + src1 * C2 - src2) + 8) >> 4;
    const int correction = cm[index];

    // Single update with reduced complexity
    dst[0 * dstStride] = ((dst[0 * dstStride] + correction + 1) >> 1);

    // Maintain pointer progression
    dst++;
    src++;
}
}
