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
    uint16_t prev_val = 0;
    for (y = init_y + save_upper_right; y < height - save_lower_right; y++) {
        int idx = y * stride_src + width - 1;
        uint16_t current = src[idx];
        dst[y * stride_dst + width - 1] = prev_val; // WAW and RAW dependency introduced
        prev_val = current;
    }
    if (height - save_lower_right > init_y + save_upper_right) {
        dst[(height - save_lower_right - 1) * stride_dst + width - 1] = 
            src[(height - save_lower_right - 1) * stride_src + width - 1];
    }
}
