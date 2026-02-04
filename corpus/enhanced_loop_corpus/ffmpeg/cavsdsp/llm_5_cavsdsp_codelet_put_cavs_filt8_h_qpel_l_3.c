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
for (i = 0; i < h; i++) {
    int offset = 0;
    dst[offset++] = cm[((-1 * src[-2 + 0] + -2 * src[-1 + 0] + 96 * src[0 + 0] + 42 * src[1 + 0] + -7 * src[2 + 0] + 0 * src[3 + 0]) + 64) >> 7];
    dst[offset++] = cm[((-1 * src[-2 + 1] + -2 * src[-1 + 1] + 96 * src[0 + 1] + 42 * src[1 + 1] + -7 * src[2 + 1] + 0 * src[3 + 1]) + 64) >> 7];
    dst[offset++] = cm[((-1 * src[-2 + 2] + -2 * src[-1 + 2] + 96 * src[0 + 2] + 42 * src[1 + 2] + -7 * src[2 + 2] + 0 * src[3 + 2]) + 64) >> 7];
    dst[offset++] = cm[((-1 * src[-2 + 3] + -2 * src[-1 + 3] + 96 * src[0 + 3] + 42 * src[1 + 3] + -7 * src[2 + 3] + 0 * src[3 + 3]) + 64) >> 7];
    dst[offset++] = cm[((-1 * src[-2 + 4] + -2 * src[-1 + 4] + 96 * src[0 + 4] + 42 * src[1 + 4] + -7 * src[2 + 4] + 0 * src[3 + 4]) + 64) >> 7];
    dst[offset++] = cm[((-1 * src[-2 + 5] + -2 * src[-1 + 5] + 96 * src[0 + 5] + 42 * src[1 + 5] + -7 * src[2 + 5] + 0 * src[3 + 5]) + 64) >> 7];
    dst[offset++] = cm[((-1 * src[-2 + 6] + -2 * src[-1 + 6] + 96 * src[0 + 6] + 42 * src[1 + 6] + -7 * src[2 + 6] + 0 * src[3 + 6]) + 64) >> 7];
    dst[offset++] = cm[((-1 * src[-2 + 7] + -2 * src[-1 + 7] + 96 * src[0 + 7] + 42 * src[1 + 7] + -7 * src[2 + 7] + 0 * src[3 + 7]) + 64) >> 7];
    dst += dstStride;
    src += srcStride;
}
}
