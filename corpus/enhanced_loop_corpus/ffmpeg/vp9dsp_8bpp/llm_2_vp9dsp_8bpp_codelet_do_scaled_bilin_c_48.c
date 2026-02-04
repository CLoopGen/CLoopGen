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
    // Variant 1: Consecutive memory access with pre-computed source indices
    int ioff_local = ioff;
    int imx_local = imx;
    for (x = 0; x < w; x++) {
        int idx = ioff_local;
        tmp_ptr[x] = (src[idx] + ((imx_local * (src[idx + 1] - src[idx]) + 8) >> 4));
        imx_local += dx;
        ioff_local += imx_local >> 4;
        imx_local &= 15;
    }
}
