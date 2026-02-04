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
    // Variant 2: Reduced loop nesting depth by unrolling the loop body (partial unrolling with step of 2)
    // This decreases effective iterations and increases instruction-level parallelism.
    // Assumes at least two elements can be safely processed (bounds preserved).
    int start_y = init_y + save_upper_left;
    int end_y = height - save_lower_left;
    int y;

    for (y = start_y; y + 1 < end_y; y += 2) {
        dst[y * stride_dst] = src[y * stride_src];
        dst[(y + 1) * stride_dst] = src[(y + 1) * stride_src];
    }

    // Handle remaining element if the range is odd
    if (y < end_y) {
        dst[y * stride_dst] = src[y * stride_src];
    }
}
