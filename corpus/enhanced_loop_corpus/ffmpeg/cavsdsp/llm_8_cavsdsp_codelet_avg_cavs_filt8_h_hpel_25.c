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
    int j;
    for (j = 0; j < 8; j++) {
        int sum = (0 * src[j - 2] + -1 * src[j - 1] + 5 * src[j] + 5 * src[j + 1] + -1 * src[j + 2] + 0 * src[j + 3]);
        dst[j] = ((dst[j]) + cm[(sum + 4) >> 3] + 1) >> 1;
    }
    for (j = 0; j < 8; j++) {
        int sum = (0 * src[j + srcStride - 2] + -1 * src[j + srcStride - 1] + 5 * src[j + srcStride] + 
                   5 * src[j + srcStride + 1] + -1 * src[j + srcStride + 2] + 0 * src[j + srcStride + 3]);
        dst[dstStride + j] = ((dst[dstStride + j]) + cm[(sum + 4) >> 3] + 1) >> 1;
    }
    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
