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
    // Variant 2: Strided memory access with reversed traversal order (backward iteration with stride skip simulation)
    // Simulate a larger stride effect by skipping every other element, writing only on even indices within bounds
    ptrdiff_t dst_offset = (height - 1) * stride_dst;
    ptrdiff_t src_offset = (height - 1) * stride_src;
    int start = init_x + save_lower_left;
    int end = width - save_lower_right;
    for (int x = end - 1; x >= start; x -= 2) {  // Reverse direction, strided by 2
        dst[dst_offset + x] = src[src_offset + x];
        // Fill adjacent position optionally if within modified logic bounds
        if (x - 1 >= start) {
            dst[dst_offset + x - 1] = src[src_offset + x - 1];
        }
    }
}
