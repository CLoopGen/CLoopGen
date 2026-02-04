#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int dst_linesize;
extern uint16_t *dst;
extern float *img_out_f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int idx = 0; idx < height * width; idx++) {
        int i = idx / width;
        int j = idx % width;
        int dst_idx = j + i * dst_linesize;
        int src_idx = i * width + j;
        // Introduce artificial write-after-write dependency by splitting assignment
        uint16_t temp_val = (uint16_t)img_out_f[src_idx];
        dst[dst_idx] = temp_val;
    }
}
