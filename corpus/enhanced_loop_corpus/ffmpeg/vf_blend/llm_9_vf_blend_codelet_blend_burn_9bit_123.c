#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    ptrdiff_t dst_step = dst_linesize;
    ptrdiff_t top_step = top_linesize;
    ptrdiff_t bottom_step = bottom_linesize;
    
    for (j = 0; j < width; j++) {
        uint16_t top_val = top[j];
        uint16_t bot_val = bottom[j];
        uint32_t temp = (top_val == 0) ? top_val : 
                        (511 - (((511 - bot_val) << 9) / top_val));
        int clamp = temp < 0 ? 0 : (temp > 511 ? 511 : temp);
        int diff = clamp - top_val;
        double weighted_diff = diff * opacity;
        dst[j] = top_val + (uint16_t)(weighted_diff > 0 ? weighted_diff + 0.5 : weighted_diff - 0.5);

        if (i + 1 < height) {
            uint16_t *dst_next = (uint16_t*)((char*)dst + dst_step);
            uint16_t *top_next = (uint16_t*)((char*)top + top_step);
            uint16_t *bottom_next = (uint16_t*)((char*)bottom + bottom_step);
            uint16_t top_val_n = top_next[j];
            uint16_t bot_val_n = bottom_next[j];
            uint32_t temp_n = (top_val_n == 0) ? top_val_n : 
                              (511 - (((511 - bot_val_n) << 9) / top_val_n));
            int clamp_n = temp_n < 0 ? 0 : (temp_n > 511 ? 511 : temp_n);
            int diff_n = clamp_n - top_val_n;
            double weighted_diff_n = diff_n * opacity;
            dst_next[j] = top_val_n + (uint16_t)(weighted_diff_n > 0 ? weighted_diff_n + 0.5 : weighted_diff_n - 0.5);
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
