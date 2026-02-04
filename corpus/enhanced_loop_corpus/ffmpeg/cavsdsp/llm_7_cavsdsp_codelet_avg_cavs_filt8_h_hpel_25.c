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
    for (int j = 0; j < 8; j++) {
        int sum = 0 * src[j-2] + -1 * src[j-1] + 5 * src[j] + 5 * src[j+1] + -1 * src[j+2] + 0 * src[j+3];
        int index = (sum + 4) >> 3;
        dst[j] = ((dst[j]) + cm[index] + 1) >> 1;
    }

    dst += dstStride;
    src += srcStride;
}
}
