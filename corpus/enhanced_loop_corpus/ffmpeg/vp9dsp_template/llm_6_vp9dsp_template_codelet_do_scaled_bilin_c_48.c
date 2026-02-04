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
    for (x = 0; x < w; x++) {
        int offset = ioff + (temp_imx >> 4);
        int diff = src[offset + 1] - src[offset];
        tmp_ptr[x] = (src[offset] + ((temp_imx * diff + 8) >> 4));
        temp_imx += dx;
        temp_imx &= 15;
    }
    imx = temp_imx;
}
