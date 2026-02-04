#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstWidth;
extern  uint8_t *src;
extern int xInc;
extern int i;
extern unsigned int xpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstWidth; i++) {
    register unsigned int xx = xpos >> 16;
    register unsigned int xalpha = (xpos & 65535) >> 9;
    register int16_t s0 = src[xx];
    register int16_t s1 = src[xx + 1];
    register int16_t diff = s1 - s0;
    dst[i] = (s0 << 7) + (diff * xalpha);
    xpos += xInc;
}
}
