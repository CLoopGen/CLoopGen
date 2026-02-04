#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < h; j++) {
    for (i = 0; i < w; i++) {
        dst[i] = cm[(36 * src[i + srcStride * 0] + 54 * src[i + 1 + srcStride * 0] + 6 * src[i + 2 + srcStride * 0] + 54 * src[i + srcStride * 1] + 81 * src[i + 1 + srcStride * 1] + 9 * src[i + 2 + srcStride * 1] + 6 * src[i + srcStride * 2] + 9 * src[i + 1 + srcStride * 2] + src[i + 2 + srcStride * 2] + 128) >> 8];
    }
    src += srcStride;
    dst += dstStride;
}

}
