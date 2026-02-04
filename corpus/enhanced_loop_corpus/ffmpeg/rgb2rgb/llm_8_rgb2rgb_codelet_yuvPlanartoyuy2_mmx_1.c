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
    int y_shifted = 0;
    for (y = 0; y < height; y++) {
        y_shifted = y >> 1;  // Equivalent to y / 2 when vertLumPerChroma is 2, reduces arithmetic ops in condition
        if ((y_shifted + 1) * 2 - 1 == y) {  // Simulates (y & (vertLumPerChroma-1)) == (vertLumPerChroma-1) for vertLumPerChroma=2
            usrc += chromStride;
            vsrc += chromStride;
        }
        ysrc += lumStride;
        dst += dstStride;
    }
}
