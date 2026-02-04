#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstWidth;
extern  uint8_t *src;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int cond;
    for (i = dstWidth - 1; i >= 0; i--) {
        cond = ((i * xInc) >> 16) >= (srcW - 1);
        dst[i] = cond ? (src[srcW - 1] * 128) : dst[i];
    }
}
