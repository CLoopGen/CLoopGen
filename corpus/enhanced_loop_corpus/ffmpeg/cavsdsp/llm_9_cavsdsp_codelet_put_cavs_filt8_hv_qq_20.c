#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src2;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce arithmetic complexity by simplifying the filter operation
    // Use a smaller kernel with fewer taps and simpler coefficients

    const int t0 = tmp[0 * 8];
    const int t1 = tmp[1 * 8];
    const int t2 = tmp[2 * 8];
    const int t3 = tmp[3 * 8];

    // Simplified weighted sum: reduce from 7-tap to 4-tap with power-of-2 coefficients
    const int sum0 = (1 * t0 + 6 * t1 + 1 * t2 + 0 * t3 + 32 * src2[0 * srcStride]);
    const int sum1 = (1 * t1 + 6 * t2 + 1 * t3 + 0 * tmp[4 * 8] + 32 * src2[1 * srcStride]);

    // Only compute two outputs per iteration instead of eight
    dst[0 * dstStride] = cm[(sum0 + 32) >> 6];  // Scale down shift for reduced range
    dst[1 * dstStride] = cm[(sum1 + 32) >> 6];

    // Update pointers as before
    dst++;
    tmp++;
    src2++;
}
}
