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
    for (j = 0; j < width; j++) {
        uint8_t top_val = top[j];
        uint8_t bottom_val = bottom[j];
        int adjusted = 0;
        if (top_val != 0) {
            int inv_bottom_sq = (255 - bottom_val) * (255 - bottom_val);
            int div_result = inv_bottom_sq / top_val;
            adjusted = (div_result > 255) ? 255 : div_result;
            adjusted = 255 - adjusted;
        }
        dst[j] = top_val + ((adjusted - top_val) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
