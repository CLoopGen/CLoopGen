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
        uint8_t temp_top = top[j];
        uint8_t temp_bottom = bottom[j];
        int term = (temp_bottom == 0) ? 0 : 255 - (((((255 - temp_top) * (255 - temp_top)) / temp_bottom) > 255) ? 255 : (((255 - temp_top) * (255 - temp_top)) / temp_bottom));
        dst[j] = temp_top + (term - temp_top) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
