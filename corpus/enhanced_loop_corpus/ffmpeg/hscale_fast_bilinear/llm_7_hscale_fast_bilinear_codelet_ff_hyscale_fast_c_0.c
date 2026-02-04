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
    register unsigned int local_xpos = xpos;
    register int16_t prev_dst = 0;
    for (i = 0; i < dstWidth; i++) {
        register unsigned int xx = local_xpos >> 16;
        register unsigned int xalpha = (local_xpos & 65535) >> 9;
        register int16_t current_val = (src[xx] << 7) + (src[xx + 1] - src[xx]) * xalpha;
        dst[i] = current_val + prev_dst; // Introduce WAW and RAW dependency: each write depends on prior write
        prev_dst = current_val;
        local_xpos += xInc;
    }
    xpos = local_xpos;
}
