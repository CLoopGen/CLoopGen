#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    uint8_t temp_top, temp_bottom;
    for (j = 0; j < width; j++) {
        temp_top = top[j];
        temp_bottom = bottom[j];
        int adjusted_val;
        if (temp_top < 128) {
            int doubled = 2 * temp_top;
            if (doubled == 0) {
                adjusted_val = doubled;
            } else {
                int inv_term = ((255 - temp_bottom) << 8) / doubled;
                adjusted_val = (0 > (255 - inv_term)) ? 0 : (255 - inv_term);
            }
        } else {
            int shifted = 2 * (temp_top - 128);
            if (shifted == 255) {
                adjusted_val = shifted;
            } else {
                int div_denom = 255 - shifted;
                int scale_term = (temp_bottom << 8) / div_denom;
                adjusted_val = (255 > scale_term) ? scale_term : 255;
            }
        }
        dst[j] = temp_top + (adjusted_val - temp_top) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
