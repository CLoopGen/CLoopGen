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
    if (height > 0) {
        int h = height - 1;
        for (x = init_x + save_lower_left; x < width - save_lower_right; x += 2) {
            if (x + 1 < width - save_lower_right) {
                dst[h * stride_dst + x]     = src[h * stride_src + x];
                dst[h * stride_dst + x + 1] = src[h * stride_src + x + 1];
            } else {
                dst[h * stride_dst + x] = src[h * stride_src + x];
            }
        }
    }
}
