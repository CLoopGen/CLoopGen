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
    int offset = (src[4] * 32 + 15) >> 5; 
    dst[0] = cm[offset];
    dst[1] = cm[offset];
    dst[2] = cm[offset];
    dst[3] = cm[offset];
    dst[4] = cm[offset];
    dst[5] = cm[offset];
    dst[6] = cm[offset];
    dst[7] = cm[offset];
    dst += dstStride;
    src += srcStride;
}
}
