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
    int unroll_factor = 4;
    int remainder = height % unroll_factor;
    int limit = height - remainder;

    for (y = 0; y < limit; y += unroll_factor) {
        for (int i = 0; i < unroll_factor; ++i) {
            int curr_y = y + i;
            if ((curr_y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
                usrc += chromStride;
                vsrc += chromStride;
            }
            ysrc += lumStride;
            dst += dstStride;
        }
    }

    for (y = limit; y < height; y++) {
        if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }
        ysrc += lumStride;
        dst += dstStride;
    }
}
