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
for (i = 0; i < dstWidth; i += 2) {
    register unsigned int xx0 = xpos >> 16;
    register unsigned int xalpha0 = (xpos & 65535) >> 9;
    register unsigned int next_xpos1 = xpos + xInc;
    register unsigned int xx1 = next_xpos1 >> 16;
    register unsigned int xalpha1 = (next_xpos1 & 65535) >> 9;

    dst[i] = (src[xx0] << 7) + (src[xx0 + 1] - src[xx0]) * xalpha0;
    if (i + 1 < dstWidth) {
        dst[i + 1] = (src[xx1] << 7) + (src[xx1 + 1] - src[xx1]) * xalpha1;
    }
    xpos += 2 * xInc;
}
}
