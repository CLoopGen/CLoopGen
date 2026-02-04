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
        int t = top[j];
        int b = bottom[j];
        int diff = 255 - t - b;
        int capped_diff = diff >= 0 ? diff : -diff;
        int blended = t + (255 - capped_diff - t) * opacity;
        dst[j] = blended;
    }
    for (j = 0; j < width; j++) {
        int t = top[j];
        int b = bottom[j];
        dst[j] = t + ((255 - abs(255 - t - b)) - t) * opacity;
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
