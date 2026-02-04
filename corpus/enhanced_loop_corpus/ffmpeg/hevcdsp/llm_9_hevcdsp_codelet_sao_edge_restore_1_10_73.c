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
    int trip_count = (width - save_lower_right) - (init_x + save_lower_left);
    int dst_offset = (height - 1) * stride_dst + (init_x + save_lower_left);
    int src_offset = (height - 1) * stride_src + (init_x + save_lower_left);
    for (x = 0; x < trip_count; x++) {
        dst[dst_offset + x] = src[src_offset + x] >> 1; // Additional arithmetic: right shift by 1
    }
}
