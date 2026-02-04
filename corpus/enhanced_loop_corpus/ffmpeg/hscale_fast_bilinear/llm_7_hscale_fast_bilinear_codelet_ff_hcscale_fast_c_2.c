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
    register unsigned int local_xpos = xpos;
    register int16_t prev_dst1 = 0, prev_dst2 = 0;
    for (i = 0; i < dstWidth; i++) {
        register unsigned int xx = local_xpos >> 16;
        register unsigned int xalpha = (local_xpos & 65535) >> 9;
        register int16_t curr_dst1 = (src1[xx] * (xalpha ^ 127) + src1[xx + 1] * xalpha) + prev_dst1;
        register int16_t curr_dst2 = (src2[xx] * (xalpha ^ 127) + src2[xx + 1] * xalpha) + prev_dst2;
        dst1[i] = curr_dst1;
        dst2[i] = curr_dst2;
        prev_dst1 = curr_dst1;
        prev_dst2 = curr_dst2;
        local_xpos += xInc;
    }
    xpos = local_xpos;
}
