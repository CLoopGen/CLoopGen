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
    int y;
    for (y = 0; y < height; y++) {
        int mod_val = y & (vertLumPerChroma - 1);
        if (mod_val == vertLumPerChroma - 1 || mod_val == vertLumPerChroma - 2) {
            if (mod_val == vertLumPerChroma - 1) {
                usrc += chromStride;
                vsrc += chromStride;
            }
        }
        ysrc += lumStride;
        dst += dstStride;
    }
}
