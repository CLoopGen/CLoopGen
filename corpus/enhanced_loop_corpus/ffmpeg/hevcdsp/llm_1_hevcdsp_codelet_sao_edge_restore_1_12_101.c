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
extern int width;
extern int height;
extern int save_upper_right;
extern int save_lower_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective nesting depth by unrolling the loop in pairs (partial unrolling)
    y = init_y + save_upper_right;
    int end = height - save_lower_right;

    // Process two iterations at a time if possible
    for (; y + 1 < end; y += 2) {
        dst[y * stride_dst + width - 1] = src[y * stride_src + width - 1];
        dst[(y + 1) * stride_dst + width - 1] = src[(y + 1) * stride_src + width - 1];
    }

    // Handle remaining iteration if any
    if (y < end) {
        dst[y * stride_dst + width - 1] = src[y * stride_src + width - 1];
    }
}
