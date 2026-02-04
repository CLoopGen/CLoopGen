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
// Reduced computational intensity: process only every fourth row and simplify computation
const int step = 4;
for (i = 0; i < w; i += step) {
    // Load fewer source values, reduce filter span
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];

    // Simplified blending using only immediate neighbors and fixed coefficients
    const int temp = (src0 + src1 + src2 + src3 + 2) >> 2;  // Average of four samples
    const int index = (temp * 3 + (1 << (SHIFT - 1))) >> SHIFT;
    const int clamped_index = (index < 0) ? 0 : ((index > 255) ? 255 : index);

    dst[0 * dstStride] = ((dst[0 * dstStride] + cm[clamped_index] + 1) >> 1);

    // Skip multiple elements to reduce trip count and arithmetic density
    dst += step;
    src += step;
}
}
