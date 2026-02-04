#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int x;
extern uint8_t *dst;
extern uint8_t *src;
extern int init_x;
extern int width;
extern int height;
extern int save_lower_right;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified indexing using precomputed base addresses
    // Precompute base offsets to minimize repeated arithmetic in loop condition and body
    ptrdiff_t dst_base = (height - 1) * stride_dst;
    ptrdiff_t src_base = (height - 1) * stride_src;
    int start = init_x + save_lower_left;
    int end = width - save_lower_right;

    for (x = start; x < end; x++) {
        dst[dst_base + x] = src[src_base + x];
    }
}
