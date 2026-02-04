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
    // Variant 2: Strided access with reversed iteration order
    for (int y = height - save_lower_right - 1; y >= init_y + save_upper_right; y--) {
        ptrdiff_t dst_offset = y * stride_dst;
        ptrdiff_t src_offset = y * stride_src;
        dst[dst_offset + width - 1] = src[src_offset + width - 1];
    }
}
