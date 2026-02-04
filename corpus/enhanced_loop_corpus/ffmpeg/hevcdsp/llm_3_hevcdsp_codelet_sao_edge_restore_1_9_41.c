#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int y;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_y;
extern int width;
extern int height;
extern int save_upper_right;
extern int save_lower_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Instead of recomputing y * stride + width - 1 each time, use pointers advanced by stride
    uint16_t* d_ptr = &dst[(init_y + save_upper_right) * stride_dst + width - 1];
    uint16_t* s_ptr = &src[(init_y + save_upper_right) * stride_src + width - 1];
    int count = (height - save_lower_right) - (init_y + save_upper_right);

    for (y = 0; y < count; y++) {
        d_ptr[0] = s_ptr[0];
        d_ptr += stride_dst;
        s_ptr += stride_src;
    }
}
