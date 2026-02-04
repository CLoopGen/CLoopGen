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
    uint8_t *local_ysrc = ysrc;
    uint8_t *local_usrc = usrc;
    uint8_t *local_vsrc = vsrc;
    uint8_t *local_dst = dst;
    int counter = 0;
    for (y = 0; y < height; y++) {
        local_ysrc += lumStride;
        local_dst += dstStride;
        counter++;
        if (counter == vertLumPerChroma) {
            local_usrc += chromStride;
            local_vsrc += chromStride;
            counter = 0;
        }
    }
    ysrc = local_ysrc;
    usrc = local_usrc;
    vsrc = local_vsrc;
    dst = local_dst;
}
