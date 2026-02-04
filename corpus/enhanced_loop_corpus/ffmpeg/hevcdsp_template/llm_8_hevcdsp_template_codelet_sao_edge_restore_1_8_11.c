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
    int start_y = init_y + save_upper_right;
    int end_y = height - save_lower_right;
    int offset = width - 1;
    ptrdiff_t dst_stride = stride_dst;
    ptrdiff_t src_stride = stride_src;
    uint8_t* d = dst;
    uint8_t* s = src;

    for (y = start_y; y < end_y; y++) {
        d[y * dst_stride + offset] = s[y * src_stride + offset];
    }
}
