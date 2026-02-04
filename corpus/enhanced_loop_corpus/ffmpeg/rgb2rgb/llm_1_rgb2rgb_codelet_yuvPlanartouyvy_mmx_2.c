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
    int y_outer, y_inner;
    int step = 2;
    for (y_outer = 0; y_outer < height; y_outer += step) {
        for (y_inner = 0; y_inner < step && (y_outer + y_inner) < height; y_inner++) {
            y = y_outer + y_inner;
            if ((y & (vertLumPerChroma - 1)) == (vertLumPerChroma - 1)) {
                usrc += chromStride;
                vsrc += chromStride;
            }
            ysrc += lumStride;
            dst += dstStride;
        }
    }
}
