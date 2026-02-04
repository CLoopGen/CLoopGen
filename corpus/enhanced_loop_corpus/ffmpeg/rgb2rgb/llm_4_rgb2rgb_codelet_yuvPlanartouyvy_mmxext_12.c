#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ysrc;
extern  uint8_t *usrc;
extern  uint8_t *vsrc;
extern uint8_t *dst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int dstStride;
extern int vertLumPerChroma;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        usrc += chromStride * ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1);
        vsrc += chromStride * ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1);
        ysrc += lumStride;
        dst += dstStride;
    }
}
