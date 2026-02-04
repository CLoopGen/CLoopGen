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
    for (i = 0; i < dstWidth; i += 2) {
        register unsigned int xx1 = (xpos) >> 16;
        register unsigned int xalpha1 = (xpos & 65535) >> 9;
        xpos += xInc;
        register unsigned int xx2 = (xpos) >> 16;
        register unsigned int xalpha2 = (xpos & 65535) >> 9;
        if (i + 1 < dstWidth) {
            dst1[i] = (src1[xx1] * (xalpha1 ^ 127) + src1[xx1 + 1] * xalpha1);
            dst2[i] = (src2[xx1] * (xalpha1 ^ 127) + src2[xx1 + 1] * xalpha1);
            dst1[i + 1] = (src1[xx2] * (xalpha2 ^ 127) + src1[xx2 + 1] * xalpha2);
            dst2[i + 1] = (src2[xx2] * (xalpha2 ^ 127) + src2[xx2 + 1] * xalpha2);
            xpos += xInc;
        } else {
            dst1[i] = (src1[xx1] * (xalpha1 ^ 127) + src1[xx1 + 1] * xalpha1);
            dst2[i] = (src2[xx1] * (xalpha1 ^ 127) + src2[xx1 + 1] * xalpha1);
        }
    }
}
