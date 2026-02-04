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
    int start_x = init_x + save_lower_left;
    int end_x = width - save_lower_right;
    ptrdiff_t dst_offset = (height - 1) * stride_dst;
    ptrdiff_t src_offset = (height - 1) * stride_src;
    for (x = start_x; x < end_x; x += 2) {
        if (x + 1 < end_x) {
            dst[dst_offset + x] = src[src_offset + x];
            dst[dst_offset + x + 1] = src[src_offset + x + 1];
        } else {
            dst[dst_offset + x] = src[src_offset + x];
        }
    }
}
