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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        int temp_top = top[j];
        int temp_bottom = bottom[j];
        int diff = 1023 - temp_top;
        int numerator = diff * diff;
        int div_result = temp_bottom == 0 ? 0 : (numerator / temp_bottom);
        int clamped = div_result > 1023 ? 1023 : div_result;
        int blend = temp_top + (1023 - clamped - temp_top) * opacity;
        dst[j] = blend;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
    if (i + 1 < height) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
