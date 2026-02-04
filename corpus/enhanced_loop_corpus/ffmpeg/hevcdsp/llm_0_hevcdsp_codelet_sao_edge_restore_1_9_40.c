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
    // Variant 1: Increased loop depth with an additional inner loop (unrolled copy with stride handling)
    // Simulating a more complex nested structure by introducing a trivial inner loop that runs once
    // This preserves functionality but increases nesting depth
    for (y = init_y + save_upper_left; y < height - save_lower_left; y++) {
        for (int inner = 0; inner < 1; inner++) {
            dst[y * stride_dst] = src[y * stride_src];
        }
    }
}
