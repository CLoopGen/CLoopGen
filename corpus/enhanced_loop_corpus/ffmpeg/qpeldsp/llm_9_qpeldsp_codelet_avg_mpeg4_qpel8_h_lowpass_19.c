#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    dst[0] = (cm[(((src[0] + src[1]) * 20 - (src[0] + src[2]) * 6 + (src[1] + src[3]) * 3 - (src[2] + src[4]) + 16) >> 5)] + 1) >> 1;
    dst[1] = (cm[(((src[1] + src[2]) * 20 - (src[0] + src[3]) * 6 + (src[0] + src[4]) * 3 - (src[1] + src[5]) + 16) >> 5)] + 1) >> 1;
    dst[2] = (cm[(((src[2] + src[3]) * 20 - (src[1] + src[4]) * 6 + (src[0] + src[5]) * 3 - (src[0] + src[6]) + 16) >> 5)] + 1) >> 1;
    dst += dstStride / 2;
    src += srcStride / 2;
}
}
