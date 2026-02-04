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
    if (w > 0) {
        x = 0;
        for (; x < w; ) {
            for (int unroll_cnt = 0; x < w && unroll_cnt < 4; unroll_cnt++) {
                tmp_ptr[x] = (src[ioff] + ((imx * (src[ioff + 1] - src[ioff]) + 8) >> 4));
                imx += dx;
                ioff += imx >> 4;
                imx &= 15;
                x++;
            }
        }
    }
}
