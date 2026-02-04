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
    int effective_height = height - save_lower_left;
    int offset = (init_y + save_upper_left) * stride_src;
    ptrdiff_t dst_offset = (init_y + save_upper_left) * stride_dst;
    
    for (y = init_y + save_upper_left; y < effective_height; y++) {
        uint8_t temp_val = src[offset];
        dst[dst_offset] = temp_val;
        offset += stride_src;
        dst_offset += stride_dst;
    }
}
