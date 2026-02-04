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
    int step = vertLumPerChroma;
    for (y = 0; y < height; y++) {
        ysrc += lumStride;
        dst += dstStride;
        if (y % step == step - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }
    }
}
