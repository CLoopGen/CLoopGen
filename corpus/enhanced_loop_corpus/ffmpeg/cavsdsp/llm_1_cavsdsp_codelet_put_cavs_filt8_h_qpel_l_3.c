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
        int j = 0;
        #pragma unroll 8
        for (; j < 8; j++) {
            const int offset = j - 2;
            dst[j] = cm[((-1 * src[offset + 0] + -2 * src[offset + 1] + 96 * src[offset + 2] + 42 * src[offset + 3] + -7 * src[offset + 4] + 0 * src[offset + 5]) + 64) >> 7];
        }
        dst += dstStride;
        src += srcStride;
    }
}
