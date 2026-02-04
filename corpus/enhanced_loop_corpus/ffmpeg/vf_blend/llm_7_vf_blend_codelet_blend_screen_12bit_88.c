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
    uint16_t local_top_prev = 0, local_bottom_prev = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t t_current = (j == 0) ? top[j] : local_top_prev;
            uint16_t b_current = (j == 0) ? bottom[j] : local_bottom_prev;
            if (j > 0) {
                t_current = (t_current + top[j]) >> 1;
                b_current = (b_current + bottom[j]) >> 1;
            } else {
                t_current = top[j];
                b_current = bottom[j];
            }
            dst[j] = t_current + (((4095 - ((4095 - t_current) * (4095 - b_current) / 4095))) - t_current) * opacity;
            local_top_prev = top[j];
            local_bottom_prev = bottom[j];
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
