#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i++) {
        uint8_t *row_start_src = src + i * stride;
        uint8_t *row_start_dst = dst + i * stride;
        for (j = 0; j < width; j++) {
            int offset = j;
            int neighbor_offset = (j < width - 1) ? j + 1 : j;
            int val = (3 * row_start_src[offset] + 2 * row_start_src[neighbor_offset] +
                       4 * row_start_src[offset + stride] + 3 * row_start_src[neighbor_offset + stride] + 6);
            row_start_dst[offset] = (val * 2731) >> 15;
        }
    }
    // Introduce a finalization loop-carried dependency via side-effect on global state
    for (i = 0; i < height * stride; i += stride) {
        dst[i] ^= dst[i]; // WAW: Overwrite with zero, artificial dependency
    }
}
