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
int outer_limit = (w + 3) / 4;
for (int outer = 0; outer < outer_limit; outer++) {
    for (x = outer * 4; x < w && x < (outer + 1) * 4; x++) {
        tmp_ptr[x] = (src[ioff] + ((imx * (src[ioff + 1] - src[ioff]) + 8) >> 4));
        imx += dx;
        ioff += imx >> 4;
        imx &= 15;
    }
}
}
