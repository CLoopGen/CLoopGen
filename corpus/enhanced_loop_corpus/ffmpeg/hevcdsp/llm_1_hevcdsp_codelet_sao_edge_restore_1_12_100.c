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
    // Variant 2: Decreased effective loop depth by collapsing into a single conditional evaluation
    // Simulate loop behavior using a single iteration with manual indexing (still uses for, but logically flat)
    int start = init_y + save_upper_left;
    int end = height - save_lower_left;
    int range = end - start;

    if (range > 0) {
        for (int i = 0; i < range; i++) {
            int idx = start + i;
            dst[idx * stride_dst] = src[idx * stride_src];
        }
    }
}
