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
    uint16_t temp = 0;
    for (y = init_y + save_upper_right; y < height - save_lower_right; y++) {
        temp = src[y * stride_src + width - 1];
        dst[y * stride_dst + width - 1] = temp;
    }
}
