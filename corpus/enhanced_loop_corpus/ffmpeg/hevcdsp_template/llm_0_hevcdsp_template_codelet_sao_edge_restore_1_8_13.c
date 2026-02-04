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
    for (int h = height - 1; h < height; h++) {
        for (x = init_x + save_lower_left; x < width - save_lower_right; x++) {
            dst[h * stride_dst + x] = src[h * stride_src + x];
        }
    }
}
