#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    // Unroll loop by factor of 2 to increase computational intensity
    if (i < h) {
        dst[0] = cm[((-1 * src[-2] + -2 * src[-1] + 96 * src[0] + 42 * src[1] + -7 * src[2]) + 64) >> 7];
        dst[1] = cm[((-1 * src[-1] + -2 * src[0] + 96 * src[1] + 42 * src[2] + -7 * src[3]) + 64) >> 7];
        dst[2] = cm[((-1 * src[0] + -2 * src[1] + 96 * src[2] + 42 * src[3] + -7 * src[4]) + 64) >> 7];
        dst[3] = cm[((-1 * src[1] + -2 * src[2] + 96 * src[3] + 42 * src[4] + -7 * src[5]) + 64) >> 7];
        dst += dstStride;
        src += srcStride;
    }
    if (i + 1 < h) {
        dst[0] = cm[((-1 * src[-2] + -2 * src[-1] + 96 * src[0] + 42 * src[1] + -7 * src[2]) + 64) >> 7];
        dst[1] = cm[((-1 * src[-1] + -2 * src[0] + 96 * src[1] + 42 * src[2] + -7 * src[3]) + 64) >> 7];
        dst[2] = cm[((-1 * src[0] + -2 * src[1] + 96 * src[2] + 42 * src[3] + -7 * src[4]) + 64) >> 7];
        dst[3] = cm[((-1 * src[1] + -2 * src[2] + 96 * src[3] + 42 * src[4] + -7 * src[5]) + 64) >> 7];
        dst += dstStride;
        src += srcStride;
    }
}
}
