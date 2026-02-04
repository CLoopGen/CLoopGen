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
    ptrdiff_t dst_base = (height - 1) * stride_dst;
    ptrdiff_t src_base = (height - 1) * stride_src;
    int adjusted_width = width - save_lower_right;
    for (x = init_x + save_lower_left; x < adjusted_width; x++) {
        uint8_t val = src[src_base + x];
        dst[dst_base + x] = (val > 128) ? val : (val + 32);
    }
}
