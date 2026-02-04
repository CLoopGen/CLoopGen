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
    int offset = ((0 * src[-2] + -7 * src[-1] + 42 * src[0] + 96 * src[1] + -2 * src[2] + -1 * src[3]) + 64) >> 7;
    dst[0] = cm[offset];
    offset = ((0 * src[-1] + -7 * src[0] + 42 * src[1] + 96 * src[2] + -2 * src[3] + -1 * src[4]) + 64) >> 7;
    dst[1] = cm[offset];
    offset = ((0 * src[0] + -7 * src[1] + 42 * src[2] + 96 * src[3] + -2 * src[4] + -1 * src[5]) + 64) >> 7;
    dst[2] = cm[offset];
    offset = ((0 * src[1] + -7 * src[2] + 42 * src[3] + 96 * src[4] + -2 * src[5] + -1 * src[6]) + 64) >> 7;
    dst[3] = cm[offset];
    offset = ((0 * src[2] + -7 * src[3] + 42 * src[4] + 96 * src[5] + -2 * src[6] + -1 * src[7]) + 64) >> 7;
    dst[4] = cm[offset];
    offset = ((0 * src[3] + -7 * src[4] + 42 * src[5] + 96 * src[6] + -2 * src[7] + -1 * src[8]) + 64) >> 7;
    dst[5] = cm[offset];
    offset = ((0 * src[4] + -7 * src[5] + 42 * src[6] + 96 * src[7] + -2 * src[8] + -1 * src[9]) + 64) >> 7;
    dst[6] = cm[offset];
    offset = ((0 * src[5] + -7 * src[6] + 42 * src[7] + 96 * src[8] + -2 * src[9] + -1 * src[10]) + 64) >> 7;
    dst[7] = cm[offset];
    dst += dstStride;
    src += srcStride;
}
}
