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
    uint16_t prev_dst_val = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int factor = (j == 0) ? 1 : 2;
            dst[j] = prev_dst_val + top[j] + ((((1) * (((top[j]) * (bottom[j])) / 65535))) - top[j]) * opacity;
            prev_dst_val = dst[j];
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
