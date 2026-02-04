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
    uint16_t temp_top, temp_bottom;
    for (j = 0; j < width; j++) {
        temp_top = top[j];
        temp_bottom = bottom[j];
        int adjusted_val = (temp_top == 0) ? 0 : ((4095 - temp_bottom) << 12) / temp_top;
        int clamped_val = (adjusted_val > 4095) ? 4095 : adjusted_val;
        int diff = (clamped_val > temp_top) ? clamped_val - temp_top : 0;
        dst[j] = temp_top + (diff * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
