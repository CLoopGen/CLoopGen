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
extern int width;
extern int height;
extern int save_upper_right;
extern int save_lower_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *dst_ptr = dst + (init_y + save_upper_right) * stride_dst + width - 1;
    uint8_t *src_ptr = src + (init_y + save_upper_right) * stride_src + width - 1;
    for (int i = init_y + save_upper_right; i < height - save_lower_right; i++) {
        *dst_ptr = *src_ptr;
        dst_ptr += stride_dst;
        src_ptr += stride_src;
    }
}
