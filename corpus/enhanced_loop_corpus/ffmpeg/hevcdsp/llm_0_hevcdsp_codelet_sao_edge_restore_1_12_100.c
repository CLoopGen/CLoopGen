#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int y;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_y;
extern int height;
extern int save_upper_left;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop depth with an additional inner loop (unrolled copy of size 2)
    for (y = init_y + save_upper_left; y < height - save_lower_left; y++) {
        dst[y * stride_dst] = src[y * stride_src];
        if (y + 1 < height - save_lower_left) {
            dst[(y + 1) * stride_dst] = src[(y + 1) * stride_src];
        }
        y++; // Manual unrolling step
    }
}
