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
int x1;
for (x1 = 0; x1 < w; x1++) {
    for (x = x1; x <= x1 && x < w; x++) {
        tmp_ptr[x] = (src[ioff] + ((imx * (src[ioff + 1] - src[ioff]) + 8) >> 4));
        imx += dx;
        ioff += imx >> 4;
        imx &= 15;
    }
}
}
