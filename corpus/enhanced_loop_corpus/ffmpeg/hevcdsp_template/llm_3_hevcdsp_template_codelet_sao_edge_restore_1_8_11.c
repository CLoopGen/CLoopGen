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
    // Variant 2: Strided access with reversed iteration order (backward traversal)
    for (int y = height - save_lower_right - 1; y >= init_y + save_upper_right; y--) {
        ptrdiff_t dst_offset = y * stride_dst + (width - 1);
        ptrdiff_t src_offset = y * stride_src + (width - 1);
        dst[dst_offset] = src[src_offset];
    }
}
