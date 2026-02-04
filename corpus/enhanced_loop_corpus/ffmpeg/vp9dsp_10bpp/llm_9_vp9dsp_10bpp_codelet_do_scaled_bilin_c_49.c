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
    int local_imx = imx;
    int local_ioff = ioff;
    for (x = 0; x < w; x++) {
        uint16_t diff = src[local_ioff + 1] - src[local_ioff];
        uint16_t interp = (local_imx * diff + 8) >> 4;
        tmp_ptr[x] = src[local_ioff] + interp;

        local_imx += dx;
        local_ioff += local_imx >> 4;
        local_imx &= 15;
    }
    imx = local_imx;
    ioff = local_ioff;
}
