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
    // Consecutive dual-step write pattern with reversed read indices
    int limit = dstWidth - (dstWidth % 2); // Ensure even count for pair processing
    for (i = 0; i < limit; i += 2) {
        register unsigned int xx1 = xpos >> 16;
        register unsigned int xalpha1 = (xpos & 65535) >> 9;
        xpos += xInc;
        register unsigned int xx2 = xpos >> 16;
        register unsigned int xalpha2 = (xpos & 65535) >> 9;

        // Access source arrays in reverse order for alternating pairs
        dst1[i]   = (src1[xx1] * (xalpha1 ^ 127) + src1[xx1 + 1] * xalpha1);
        dst2[i]   = (src2[xx1] * (xalpha1 ^ 127) + src2[xx1 + 1] * xalpha1);
        dst1[i+1] = (src1[xx2 + 1] * (xalpha2 ^ 127) + src1[xx2] * xalpha2); // Swapped access
        dst2[i+1] = (src2[xx2 + 1] * (xalpha2 ^ 127) + src2[xx2] * xalpha2); // Swapped access
        xpos += xInc;
    }
    // Handle leftover element if dstWidth is odd
    if (i < dstWidth) {
        register unsigned int xx = xpos >> 16;
        register unsigned int xalpha = (xpos & 65535) >> 9;
        dst1[i] = (src1[xx] * (xalpha ^ 127) + src1[xx + 1] * xalpha);
        dst2[i] = (src2[xx] * (xalpha ^ 127) + src2[xx + 1] * xalpha);
    }
}
