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
for (i = 0; i < h; i += 2) {
    int j;
    for (j = 0; j < 8; j++) {
        int index = ((src[j] + src[j+1]) * 20 - (src[j-1 >= 0 ? j-1 : j+2] + src[j+2]) * 6 + 
                    (src[j-2 >= 0 ? j-2 : j+3] + src[j+3]) * 3 - (src[j-3 >= 0 ? j-3 : j+4] + src[j+4])) + 16;
        dst[j] = ((dst[j] + cm[(index >> 5)] + 1) >> 1);
    }
    for (j = 8; j < 16; j++) {
        int val = (src[j] * 3 + src[j-1] * 2 - src[j-2]) + 16;
        dst[j] = ((dst[j] + cm[(val >> 5)] + 1) >> 1);
    }
    dst += dstStride * 2;
    src += srcStride * 2;
}
}
