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
    register unsigned int temp_xpos = xpos;
    for (i = 0; i < dstWidth; i++) {
        register unsigned int xx = temp_xpos >> 16;
        register unsigned int xalpha = (temp_xpos & 65535) >> 9;
        register uint8_t val1_xx = src1[xx];
        register uint8_t val1_xx1 = src1[xx + 1];
        register uint8_t val2_xx = src2[xx];
        register uint8_t val2_xx1 = src2[xx + 1];
        register int16_t result1 = (val1_xx * (xalpha ^ 127) + val1_xx1 * xalpha);
        register int16_t result2 = (val2_xx * (xalpha ^ 127) + val2_xx1 * xalpha);
        dst1[i] = result1;
        dst2[i] = result2;
        temp_xpos += xInc;
    }
}
