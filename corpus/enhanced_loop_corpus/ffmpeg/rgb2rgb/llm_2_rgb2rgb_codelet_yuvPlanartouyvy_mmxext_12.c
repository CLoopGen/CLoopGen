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
    // Variant 1: Consecutive memory access with pointer pre-increment and batch stride adjustment
    // Instead of conditionally updating usrc/vsrc every few rows, we simulate a more linear access pattern
    // by calculating effective strides that account for chroma subsampling in a flattened manner.
    
    uint8_t *y_ptr = ysrc;
    uint8_t *u_ptr = usrc;
    uint8_t *v_ptr = vsrc;
    uint8_t *d_ptr = dst;

    int chroma_update_interval = vertLumPerChroma;
    int chroma_countdown = chroma_update_interval;

    for (y = 0; y < height; y++) {
        y_ptr += lumStride;
        d_ptr += dstStride;

        chroma_countdown--;
        if (chroma_countdown == 0) {
            u_ptr += chromStride;
            v_ptr += chromStride;
            chroma_countdown = chroma_update_interval;
        }
    }

    // Update extern pointers to reflect final positions
    ysrc = y_ptr;
    usrc = u_ptr;
    vsrc = v_ptr;
    dst = d_ptr;
}
