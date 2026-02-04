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
    int step = 2;
    int adjusted_init = init_y + save_upper_right;
    int adjusted_end = height - save_lower_right;
    int unrolled_width = width - 1;
    ptrdiff_t scaled_stride_dst = stride_dst;
    ptrdiff_t scaled_stride_src = stride_src;

    for (y = adjusted_init; y < adjusted_end; y += step) {
        dst[y * scaled_stride_dst + unrolled_width] = src[y * scaled_stride_src + unrolled_width];
        if (y + 1 < adjusted_end) {
            dst[(y + 1) * scaled_stride_dst + unrolled_width] = src[(y + 1) * scaled_stride_src + unrolled_width];
        }
    }
}
