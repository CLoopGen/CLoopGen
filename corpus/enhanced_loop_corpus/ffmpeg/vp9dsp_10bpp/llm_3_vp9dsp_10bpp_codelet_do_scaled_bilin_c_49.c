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
    // Variant 2: Strided Memory Access Pattern
    // Instead of irregular increments, we impose a fixed stride on src access.
    // This simulates processing every 'stride'-th element, here stride = 2.
    const int stride = 2;
    for (x = 0; x < w; x++) {
        int idx = ioff * stride;  // strided index into src
        tmp_ptr[x] = (src[idx] + ((imx * (src[idx + stride] - src[idx]) + 8) >> 4));
        imx += dx;
        ioff += imx >> 4;
        imx &= 15;
    }
}
