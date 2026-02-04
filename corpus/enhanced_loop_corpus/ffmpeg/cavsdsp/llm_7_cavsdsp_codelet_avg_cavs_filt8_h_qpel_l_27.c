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
        int j;
        for (j = 0; j < 8; j++) {
            int coeff = (-1 * src[j - 2] + -2 * src[j - 1] + 96 * src[j] + 42 * src[j + 1] + -7 * src[j + 2] + 0 * src[j + 3]);
            uint8_t filtered = cm[(coeff + 64) >> 7];
            dst[j] = ((dst[j]) + filtered + 1) >> 1;
        }

        dst += dstStride;
        src += srcStride;
    }
}
