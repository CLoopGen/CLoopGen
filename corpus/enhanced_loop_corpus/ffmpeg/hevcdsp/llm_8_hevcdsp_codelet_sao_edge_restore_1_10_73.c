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
    int start = init_x + save_lower_left;
    int end = width - save_lower_right;
    int idx_dst_base = (height - 1) * stride_dst;
    int idx_src_base = (height - 1) * stride_src;
    for (x = start; x < end; x += 2) {
        dst[idx_dst_base + x] = src[idx_src_base + x];
        if (x + 1 < end) {
            dst[idx_dst_base + x + 1] = src[idx_src_base + x + 1];
        }
    }
}
