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
    dst[0] = cm[((-1 * src[-1] + 6 * src[0] + 6 * src[1] - 1 * src[2]) + 4) >> 3];
    dst[1] = cm[((-1 * src[0] + 6 * src[1] + 6 * src[2] - 1 * src[3]) + 4) >> 3];
    dst[2] = cm[((-1 * src[1] + 6 * src[2] + 6 * src[3] - 1 * src[4]) + 4) >> 3];
    dst[3] = cm[((-1 * src[2] + 6 * src[3] + 6 * src[4] - 1 * src[5]) + 4) >> 3];
    dst += dstStride;
    src += srcStride;
}
}
