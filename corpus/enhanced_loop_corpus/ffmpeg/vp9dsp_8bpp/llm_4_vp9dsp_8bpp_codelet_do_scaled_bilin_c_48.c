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
        int diff = src[ioff + 1] - src[ioff];
        tmp_ptr[x] = (src[ioff] + ((imx * diff + 8) >> 4));
        imx += dx;
        if (imx >= 16) {
            ioff += imx >> 4;
            imx &= 15;
        }
    }
}
