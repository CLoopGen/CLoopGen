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
    int offset = (-1 * src[-2] + -2 * src[-1] + 96 * src[0] + 42 * src[1] + -7 * src[2]) + 64;
    dst[0] = ((dst[0]) + cm[offset >> 7] + 1) >> 1;

    offset = (-1 * src[-1] + -2 * src[0] + 96 * src[1] + 42 * src[2] + -7 * src[3]) + 64;
    dst[1] = ((dst[1]) + cm[offset >> 7] + 1) >> 1;

    offset = (-1 * src[0] + -2 * src[1] + 96 * src[2] + 42 * src[3] + -7 * src[4]) + 64;
    dst[2] = ((dst[2]) + cm[offset >> 7] + 1) >> 1;

    offset = (-1 * src[1] + -2 * src[2] + 96 * src[3] + 42 * src[4] + -7 * src[5]) + 64;
    dst[3] = ((dst[3]) + cm[offset >> 7] + 1) >> 1;

    dst += dstStride;
    src += srcStride;
}
}
