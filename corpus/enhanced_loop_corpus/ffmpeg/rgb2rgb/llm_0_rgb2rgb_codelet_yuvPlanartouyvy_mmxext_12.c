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
    for (int outer = 0; outer < height; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            if ((outer & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
                usrc += chromStride;
                vsrc += chromStride;
            }
            ysrc += lumStride;
            dst += dstStride;
        }
    }
}
