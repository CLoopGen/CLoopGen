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
    uint8_t *temp_ysrc = ysrc;
    uint8_t *temp_usrc = usrc;
    uint8_t *temp_vsrc = vsrc;
    uint8_t *temp_dst = dst;
    for (y = 0; y < height; y++) {
        temp_ysrc += lumStride;
        temp_dst += dstStride;
        if ((y & (vertLumPerChroma - 1)) == (vertLumPerChroma - 1)) {
            temp_usrc += chromStride;
            temp_vsrc += chromStride;
        }
    }
    ysrc = temp_ysrc;
    usrc = temp_usrc;
    vsrc = temp_vsrc;
    dst = temp_dst;
}
