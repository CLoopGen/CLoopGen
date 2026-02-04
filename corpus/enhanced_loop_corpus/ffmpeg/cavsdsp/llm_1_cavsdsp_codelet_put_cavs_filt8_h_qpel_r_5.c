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
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < 2; j++) {
            dst[0 + j*4] = cm[((0 * src[-2 + j*4] + -7 * src[-1 + j*4] + 42 * src[0 + j*4] + 96 * src[1 + j*4] + -2 * src[2 + j*4] + -1 * src[3 + j*4]) + 64) >> 7];
            dst[1 + j*4] = cm[((0 * src[-1 + j*4] + -7 * src[0 + j*4] + 42 * src[1 + j*4] + 96 * src[2 + j*4] + -2 * src[3 + j*4] + -1 * src[4 + j*4]) + 64) >> 7];
            dst[2 + j*4] = cm[((0 * src[0 + j*4] + -7 * src[1 + j*4] + 42 * src[2 + j*4] + 96 * src[3 + j*4] + -2 * src[4 + j*4] + -1 * src[5 + j*4]) + 64) >> 7];
            dst[3 + j*4] = cm[((0 * src[1 + j*4] + -7 * src[2 + j*4] + 42 * src[3 + j*4] + 96 * src[4 + j*4] + -2 * src[5 + j*4] + -1 * src[6 + j*4]) + 64) >> 7];
        }
        dst += dstStride;
        src += srcStride;
    }
}
