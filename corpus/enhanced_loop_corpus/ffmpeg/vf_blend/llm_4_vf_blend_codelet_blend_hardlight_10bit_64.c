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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t b_val = bottom[j];
        uint16_t t_val = top[j];
        int use_fast_path = b_val < 512;
        dst[j] = t_val;
        if (use_fast_path) {
            dst[j] += (((2 * (b_val * t_val / 1023)) - t_val) * opacity);
        } else {
            dst[j] += (((1023 - (2 * ((1023 - b_val) * (1023 - t_val) / 1023))) - t_val) * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
