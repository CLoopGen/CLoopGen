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
    int outer_limit = (w + 15) / 16;
    for (int xo = 0; xo < outer_limit; xo++) {
        for (int xi = 0; xi < 16; xi++) {
            x = xo * 16 + xi;
            if (x >= w) break;
            tmp_ptr[x] = (src[ioff] + ((imx * (src[ioff + 1] - src[ioff]) + 8) >> 4));
            imx += dx;
            ioff += imx >> 4;
            imx &= 15;
        }
    }
}
