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
    int updateChroma = 0;
    for (y = 0; y < height; y++) {
        updateChroma = (y + 1) % vertLumPerChroma == 0 ? 1 : 0;
        if (updateChroma) {
            usrc += chromStride;
            vsrc += chromStride;
        }
        ysrc += lumStride;
        dst += dstStride;
    }
}
