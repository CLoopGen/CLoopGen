#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int dx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;
extern int imx;
extern int ioff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w; x++) {
        uint8_t base_val = src[ioff];
        int adjusted = ((imx * (src[ioff + 1] - base_val) + 8) >> 4);
        tmp_ptr[x] = base_val + adjusted;

        imx += dx;
        int shift = imx >> 4;
        if (shift > 0) {
            ioff += shift;
            imx -= (shift << 4);
        }
    }
}
