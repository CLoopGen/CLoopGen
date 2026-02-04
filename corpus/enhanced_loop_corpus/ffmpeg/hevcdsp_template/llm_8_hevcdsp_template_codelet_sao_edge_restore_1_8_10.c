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
    // Variant 1: Increased computational intensity with unrolled loop (2x unrolling) and additional arithmetic operations.
    // This increases the number of arithmetic operations per iteration and reduces trip count by half.
    int start_y = init_y + save_upper_left;
    int end_y = height - save_lower_left;
    int remainder = (end_y - start_y) % 2;
    int unrolled_end = start_y + (end_y - start_y - remainder);

    for (y = start_y; y < unrolled_end; y += 2) {
        dst[y * stride_dst] = src[y * stride_src];
        dst[(y + 1) * stride_dst] = src[(y + 1) * stride_src];
    }
    // Handle leftover iteration if any
    if (remainder == 1) {
        dst[y * stride_dst] = src[y * stride_src];
    }
}
