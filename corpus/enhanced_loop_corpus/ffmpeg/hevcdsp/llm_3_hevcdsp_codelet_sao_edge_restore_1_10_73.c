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
    // Variant 2: Strided memory access with a fixed step (e.g., every 2nd element) to demonstrate non-unit stride pattern
    ptrdiff_t dst_offset = (height - 1) * stride_dst;
    ptrdiff_t src_offset = (height - 1) * stride_src;
    int start = init_x + save_lower_left;
    int end = width - save_lower_right;
    int step = 2; // Stride of 2 for irregular access pattern
    for (int x = start; x < end; x += step) {
        dst[dst_offset + x] = src[src_offset + x];
    }
    // Handle final element if range length is odd and last index was skipped
    if ((end - start) > 0 && (end - 1 - start) % 2 == 0) {
        int last_x = end - 1;
        if (last_x >= start) {
            dst[dst_offset + last_x] = src[src_offset + last_x];
        }
    }
}
