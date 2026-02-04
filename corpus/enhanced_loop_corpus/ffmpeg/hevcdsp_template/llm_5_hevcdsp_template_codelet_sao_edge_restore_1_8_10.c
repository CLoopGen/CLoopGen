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
    // Variant 2: Simplify control by unrolling the loop twice and using conditional bounds adjustment
    int start = init_y + save_upper_left;
    int end = height - save_lower_left;

    // Handle odd start to ensure alignment for unrolling
    if (start < end && (start & 1)) {
        dst[start * stride_dst] = src[start * stride_src];
        start++;
    }

    // Unroll by 2: process two iterations per loop step
    for (y = start; y + 1 < end; y += 2) {
        dst[y * stride_dst] = src[y * stride_src];
        dst[(y + 1) * stride_dst] = src[(y + 1) * stride_src];
    }

    // Handle remaining iteration if end is odd
    if (y < end) {
        dst[y * stride_dst] = src[y * stride_src];
    }
}
