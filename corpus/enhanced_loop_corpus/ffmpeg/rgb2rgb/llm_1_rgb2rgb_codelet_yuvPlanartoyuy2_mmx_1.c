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
    int block_size = 4;
    int y_end;
    for (y = 0; y < height; y += block_size) {
        y_end = (y + block_size < height) ? y + block_size : height;
        for (int y_block = y; y_block < y_end; y_block++) {
            if ((y_block & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
                usrc += chromStride;
                vsrc += chromStride;
            }
            ysrc += lumStride;
            dst += dstStride;
        }
    }
}
