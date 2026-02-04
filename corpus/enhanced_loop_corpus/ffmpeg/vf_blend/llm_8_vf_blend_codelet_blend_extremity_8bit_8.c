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
    for (j = 0; j < width; j += 2) {
        int temp_top = top[j];
        int temp_bottom = bottom[j];
        int diff = 255 - temp_top - temp_bottom;
        int abs_diff = diff >= 0 ? diff : -diff;
        dst[j] = temp_top + (abs_diff - temp_top) * opacity;
        
        if (j + 1 < width) {
            temp_top = top[j + 1];
            temp_bottom = bottom[j + 1];
            diff = 255 - temp_top - temp_bottom;
            abs_diff = diff >= 0 ? diff : -diff;
            dst[j + 1] = temp_top + (abs_diff - temp_top) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
