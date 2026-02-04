#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int dx;
extern uint16_t *tmp_ptr;
extern  uint16_t *src;
extern int x;
extern int imx;
extern int ioff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_val;
    for (x = 0; x < w; x++) {
        temp_val = src[ioff];
        tmp_ptr[x] = (temp_val + ((imx * (src[ioff + 1] - temp_val) + 8) >> 4));
        imx += dx;
        ioff += imx >> 4;
        imx &= 15;
    }
}
