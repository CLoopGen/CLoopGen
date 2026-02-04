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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        int top_val = top[j];
        int bottom_val = bottom[j];
        int diff = 255 - top_val;
        int numerator = diff * diff;
        int div_result = (bottom_val == 0) ? 0 : (numerator / bottom_val);
        int clamped = (div_result > 255) ? 255 : div_result;
        int blend = (bottom_val == 0) ? 0 : 255 - clamped;
        dst[j] = top_val + (blend - top_val) * opacity;
    }
    for (j = 0; j < width; j++) {
        int top_val = top[j] + top_linesize;
        int bottom_val = bottom[j] + bottom_linesize;
        int diff = 255 - top_val;
        int numerator = diff * diff;
        int div_result = (bottom_val == 0) ? 0 : (numerator / bottom_val);
        int clamped = (div_result > 255) ? 255 : div_result;
        int blend = (bottom_val == 0) ? 0 : 255 - clamped;
        dst[dst_linesize + j] = top_val + (blend - top_val) * opacity;
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
