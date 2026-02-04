#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst1;
extern int16_t *dst2;
extern int dstWidth;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int xInc;
extern int i;
extern unsigned int xpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstWidth; i++) {
    register unsigned int xx = xpos >> 16;
    register unsigned int xalpha = (xpos & 65535) >> 9;
    xpos += xInc;
    if (xx % 2 == 0) {
        dst1[i] = (src1[xx] * (xalpha ^ 127) + src1[xx + 1] * xalpha);
        dst2[i] = (src2[xx] * (xalpha ^ 127) + src2[xx + 1] * xalpha);
    } else {
        dst1[i] = src1[xx] * 64;
        dst2[i] = src2[xx] * 64;
    }
}
}
