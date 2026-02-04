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
        dst[j] = temp_top + (((temp_top == 0) ? 0 : 255 - ((((255 - temp_bottom) * (255 - temp_bottom)) / temp_top) > (255) ? (255) : (((255 - temp_bottom) * (255 - temp_bottom)) / temp_top))) - temp_top) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
