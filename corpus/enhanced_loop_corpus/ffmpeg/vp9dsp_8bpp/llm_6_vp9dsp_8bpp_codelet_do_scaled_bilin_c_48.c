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
    int temp_imx = imx;
    int temp_ioff = ioff;
    for (x = 0; x < w; x++) {
        tmp_ptr[x] = (src[temp_ioff] + ((temp_imx * (src[temp_ioff + 1] - src[temp_ioff]) + 8) >> 4));
        temp_imx += dx;
        temp_ioff += temp_imx >> 4;
        temp_imx &= 15;
    }
    imx = temp_imx;
    ioff = temp_ioff;
}
