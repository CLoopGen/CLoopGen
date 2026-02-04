#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int x;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_x;
extern int width;
extern int height;
extern int save_lower_right;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations using precomputed base indices and simplified addressing
    ptrdiff_t dst_base = (height - 1) * stride_dst;
    ptrdiff_t src_base = (height - 1) * stride_src;
    int start_x = init_x + save_lower_left;
    int end_x = width - save_lower_right;
    for (x = start_x; x < end_x; x++) {
        dst[dst_base + x] = src[src_base + x];
    }
}
