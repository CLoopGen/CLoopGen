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
        uint16_t blended;
        int32_t shifted = bottom[j] - 32768;
        int use_shifted_path = bottom[j] >= 32768;

        if (use_shifted_path) {
            blended = (top[j] > 2 * shifted) ? top[j] : 2 * shifted;
        } else {
            blended = (top[j] > 2 * bottom[j]) ? 2 * bottom[j] : top[j];
        }
        dst[j] = top[j] + (blended - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
