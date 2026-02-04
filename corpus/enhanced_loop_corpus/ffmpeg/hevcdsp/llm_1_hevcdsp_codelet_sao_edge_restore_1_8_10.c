#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int y;
extern uint8_t *dst;
extern uint8_t *src;
extern int init_y;
extern int height;
extern int save_upper_left;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective loop depth by unrolling the loop twice with conditional checks (partial unrolling)
    int start = init_y + save_upper_left;
    int end = height - save_lower_left;
    int i = start;

    // Handle two iterations per loop cycle
    for (; i <= end - 2; i += 2) {
        dst[i * stride_dst] = src[i * stride_src];
        dst[(i + 1) * stride_dst] = src[(i + 1) * stride_src];
    }

    // Handle remaining iteration if count is odd
    if (i == end - 1) {
        dst[i * stride_dst] = src[i * stride_src];
    }
}
