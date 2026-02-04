#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    int j;
    for (j = 0; j < 8; j++) {
        dst[j] = cm[(-(src[j-1] + src[j+2]) + src[j] * C1 + src[j+1] * C2 + 8) >> 4];
    }
    dst += dstStride;
    src += srcStride;

    if (i + 1 < h) {
        for (j = 0; j < 8; j++) {
            dst[j] = cm[(-(src[j-1] + src[j+2]) + src[j] * C1 + src[j+1] * C2 + 8) >> 4];
        }
        dst += dstStride;
        src += srcStride;
    }
}
}
