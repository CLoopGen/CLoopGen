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
    int y_local;
    uint8_t *usrc_local = usrc;
    uint8_t *vsrc_local = vsrc;
    uint8_t *ysrc_local = ysrc;
    uint8_t *dst_local = dst;

    for (y_local = 0; y_local < height; y_local++) {
        ysrc_local += lumStride;
        dst_local += dstStride;
        if ((y_local & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc_local += chromStride;
            vsrc_local += chromStride;
        }
    }

    // Update global pointers based on final computed values
    ysrc = ysrc_local;
    dst = dst_local;
    usrc = usrc_local;
    vsrc = vsrc_local;
    y = y_local;
}
