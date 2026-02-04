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
        for (j = 0; j < 8; j++) {
            dst[j] = cm[((0 * src[j - 2] + -7 * src[j - 1] + 42 * src[j] + 96 * src[j + 1] + -2 * src[j + 2] + -1 * src[j + 3]) + 64) >> 7];
        }
        dst += dstStride;
        src += srcStride;
    }
}
