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
        int min_val = (top_val < bottom_val) ? top_val : bottom_val;
        int max_val = (top_val > bottom_val) ? top_val : bottom_val;
        int diff = (max_val - min_val + 255) * opacity;
        dst[j] = top_val + (diff - top_val);
    }
    for (j = 0; j < width; j++) {
        int top_val = top[j];
        dst[j] = (top_val * 0.7) + (dst[j] * 0.3);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
