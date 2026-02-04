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
        // Modified to strided access with step of 2, wrapping within bounds
        int stride = 2;
        int effective_idx = (xx * stride) % (dstWidth * 2); // Simulate bounded strided read
        if (effective_idx + 1 >= dstWidth * 2) effective_idx = dstWidth * 2 - 2;
        dst1[i] = (src1[effective_idx] * (xalpha ^ 127) + src1[effective_idx + 1] * xalpha);
        dst2[i] = (src2[effective_idx] * (xalpha ^ 127) + src2[effective_idx + 1] * xalpha);
        xpos += xInc;
    }
}
