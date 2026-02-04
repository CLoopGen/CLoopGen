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
for (i = 0; i < w; i++) {
    // Reduce computational intensity: collapse multiple operations into fewer memory accesses and arithmetic steps
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];

    // Simplified filter: use only three-tap instead of the full nine-tap pattern, reducing arithmetic density
    dst[0 * dstStride] = cm[(src0 * C1 + src1 * C2 - src2 + 8) >> 4];

    // Only update one output point per iteration, increasing trip count effectiveness but lowering per-iteration cost
    dst++;
    src++;
}
}
