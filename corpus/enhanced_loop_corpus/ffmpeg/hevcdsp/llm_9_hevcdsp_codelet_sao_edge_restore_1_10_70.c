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
    int step = 2;
    int adjusted_start = init_y + save_upper_left;
    int adjusted_end = height - save_lower_left;

    // Unroll loop to process two iterations per loop cycle
    for (y = adjusted_start; y < adjusted_end - 1; y += step) {
        dst[y * stride_dst] = src[y * stride_src];
        dst[(y + 1) * stride_dst] = src[(y + 1) * stride_src];
    }

    // Handle remaining iteration if trip count is odd
    if (y == adjusted_end - 1) {
        dst[y * stride_dst] = src[y * stride_src];
    }
}
