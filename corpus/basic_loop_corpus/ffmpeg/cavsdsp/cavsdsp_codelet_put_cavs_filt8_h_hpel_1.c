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
    dst[0] = cm[((0 * src[-2] + -1 * src[-1] + 5 * src[0] + 5 * src[1] + -1 * src[2] + 0 * src[3]) + 4) >> 3];
    dst[1] = cm[((0 * src[-1] + -1 * src[0] + 5 * src[1] + 5 * src[2] + -1 * src[3] + 0 * src[4]) + 4) >> 3];
    dst[2] = cm[((0 * src[0] + -1 * src[1] + 5 * src[2] + 5 * src[3] + -1 * src[4] + 0 * src[5]) + 4) >> 3];
    dst[3] = cm[((0 * src[1] + -1 * src[2] + 5 * src[3] + 5 * src[4] + -1 * src[5] + 0 * src[6]) + 4) >> 3];
    dst[4] = cm[((0 * src[2] + -1 * src[3] + 5 * src[4] + 5 * src[5] + -1 * src[6] + 0 * src[7]) + 4) >> 3];
    dst[5] = cm[((0 * src[3] + -1 * src[4] + 5 * src[5] + 5 * src[6] + -1 * src[7] + 0 * src[8]) + 4) >> 3];
    dst[6] = cm[((0 * src[4] + -1 * src[5] + 5 * src[6] + 5 * src[7] + -1 * src[8] + 0 * src[9]) + 4) >> 3];
    dst[7] = cm[((0 * src[5] + -1 * src[6] + 5 * src[7] + 5 * src[8] + -1 * src[9] + 0 * src[10]) + 4) >> 3];
    dst += dstStride;
    src += srcStride;
}

}
