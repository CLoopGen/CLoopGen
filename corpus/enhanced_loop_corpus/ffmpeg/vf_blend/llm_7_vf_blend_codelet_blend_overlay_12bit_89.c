#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t idx;
    for (i = 0; i < height; i++) {
        idx = i * dst_linesize;
        for (j = 0; j < width; j++) {
            ptrdiff_t t_idx = i * top_linesize + j;
            ptrdiff_t b_idx = i * bottom_linesize + j;
            dst[idx + j] = top[t_idx] + (((top[t_idx] < 2048) ? 
                ((2) * (((top[t_idx]) * (bottom[b_idx])) / 4095)) : 
                (4095 - (2) * ((4095 - (top[t_idx])) * (4095 - (bottom[b_idx])) / 4095))) - top[t_idx]) * opacity;
        }
    }
    // Eliminate loop-carried pointer updates by computing addresses per iteration
    // This removes WAW and WAR hazards on pointer variables across iterations
    // All memory accesses now use base + offset addressing, removing dependency on prior pointer arithmetic
}
