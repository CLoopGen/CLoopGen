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
    int offset_dst = (height - 1) * stride_dst + init_x + save_lower_left;
    int offset_src = (height - 1) * stride_src + init_x + save_lower_left;
    for (x = init_x + save_lower_left; x < width - save_lower_right; x++) {
        dst[offset_dst] = src[offset_src];
        offset_dst++;
        offset_src++;
    }
}
