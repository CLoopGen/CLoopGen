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
        register unsigned int inv_xalpha = 127 - xalpha;
        int16_t val1 = (int16_t)(src1[xx] * inv_xalpha + src1[xx + 1] * xalpha + 4) >> 3;
        int16_t val2 = (int16_t)(src2[xx] * inv_xalpha + src2[xx + 1] * xalpha + 4) >> 3;
        dst1[i] = val1;
        dst2[i] = val2;
        xpos += xInc << 1;
    }
}
