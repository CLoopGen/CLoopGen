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
        uint16_t temp_bottom = bottom[j];
        uint16_t temp_top = top[j];
        uint16_t result;
        if (temp_bottom < 2048) {
            result = (temp_top > (2 * temp_bottom)) ? (2 * temp_bottom) : temp_top;
        } else {
            int adjusted = 2 * (temp_bottom - 2048);
            result = (temp_top > adjusted) ? temp_top : adjusted;
        }
        dst[j] = temp_top + (result - temp_top) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
