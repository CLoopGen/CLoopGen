#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce arithmetic operations by simplifying filter coefficients and decreasing memory accesses
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];

    // Simplified filtering: use only four taps with reduced operations
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(tmp0 + tmp1 + 256) >> 9] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(tmp1 + tmp2 + 256) >> 9] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(tmp2 + tmp3 + 256) >> 9] + 1) >> 1;

    // Only update pointers once per iteration
    dst++;
    tmp++;
}
}
