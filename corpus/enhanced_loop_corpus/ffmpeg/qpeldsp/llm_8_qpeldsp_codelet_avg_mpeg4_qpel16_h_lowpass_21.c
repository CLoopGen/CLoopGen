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
    int j;
    for (j = 0; j < 16; j += 4) {
        dst[j+0] = (((dst[j+0]) + cm[((((src[j+0] + src[j+1]) * 20 - (src[j+0] + src[j+2]) * 6 + (src[j+1] + src[j+3]) * 3 - (src[j+2] + src[j+4])) + 16) >> 5)] + 1) >> 1);
        dst[j+1] = (((dst[j+1]) + cm[((((src[j+1] + src[j+2]) * 20 - (src[j+0] + src[j+3]) * 6 + (src[j+0] + src[j+4]) * 3 - (src[j+1] + src[j+5])) + 16) >> 5)] + 1) >> 1);
        dst[j+2] = (((dst[j+2]) + cm[((((src[j+2] + src[j+3]) * 20 - (src[j+1] + src[j+4]) * 6 + (src[j+0] + src[j+5]) * 3 - (src[j+0] + src[j+6])) + 16) >> 5)] + 1) >> 1);
        dst[j+3] = (((dst[j+3]) + cm[((((src[j+3] + src[j+4]) * 20 - (src[j+2] + src[j+5]) * 6 + (src[j+1] + src[j+6]) * 3 - (src[j+0] + src[j+7])) + 16) >> 5)] + 1) >> 1);
    }
    dst += dstStride;
    src += srcStride;
}
}
