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
    // Variant 1: Consecutive memory access with pointer arithmetic
    // Instead of computing array indices repeatedly, use pointers that advance consecutively
    uint16_t *dst_ptr = &dst[(height - 1) * stride_dst + init_x + save_lower_left];
    uint16_t *src_ptr = &src[(height - 1) * stride_src + init_x + save_lower_left];
    int count = (width - save_lower_right) - (init_x + save_lower_left);
    for (int i = 0; i < count; i++) {
        dst_ptr[i] = src_ptr[i];
    }
}
