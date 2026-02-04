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
    for (j = 0; j < width; j += 2) {
        int diff1 = top[j] - bottom[j];
        int abs_diff1 = diff1 >= 0 ? diff1 : -diff1;
        dst[j] = top[j] + (abs_diff1 - top[j]) * opacity;

        if (j + 1 < width) {
            int diff2 = top[j+1] - bottom[j+1];
            int abs_diff2 = diff2 >= 0 ? diff2 : -diff2;
            dst[j+1] = top[j+1] + (abs_diff2 - top[j+1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
