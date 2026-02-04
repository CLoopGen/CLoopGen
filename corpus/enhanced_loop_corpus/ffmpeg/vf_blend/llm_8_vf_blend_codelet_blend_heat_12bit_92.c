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
    for (j = 0; j < width; j += 2) {
        uint16_t temp_top = top[j];
        uint16_t temp_bottom = bottom[j];
        uint16_t inv_bottom_sq = (4095 - temp_bottom) * (4095 - temp_bottom);
        uint16_t blend_val = (temp_top == 0) ? 0 : (inv_bottom_sq / temp_top);
        if (blend_val > 4095) blend_val = 4095;
        dst[j] = temp_top + ((4095 - blend_val - temp_top) * opacity);

        if (j + 1 < width) {
            temp_top = top[j+1];
            temp_bottom = bottom[j+1];
            inv_bottom_sq = (4095 - temp_bottom) * (4095 - temp_bottom);
            blend_val = (temp_top == 0) ? 0 : (inv_bottom_sq / temp_top);
            if (blend_val > 4095) blend_val = 4095;
            dst[j+1] = temp_top + ((4095 - blend_val - temp_top) * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
