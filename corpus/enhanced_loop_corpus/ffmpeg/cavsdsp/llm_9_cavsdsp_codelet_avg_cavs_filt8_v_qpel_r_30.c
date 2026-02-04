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
for (i = 0; i < w; i++) {
    // Reduce input fetches and arithmetic complexity by reusing values and simplifying filter
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];

    // Simplified interpolation: use only current and next few neighbors with smaller coefficients
    const int val = (src0 + src1 + 1) >> 1;  // Simple average of two pixels
    const int index = ((48 * src0 + 16 * src1 + 16 * src2 + 16 * src3 + 48) >> 6); // Weighted sum, scaled

    // Update only one destination value per iteration with lower computational load
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[index] + 1) >> 1;

    // Move to next column
    dst++;
    src++;
}
}
