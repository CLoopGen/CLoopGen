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
    int skip_row = (opacity <= 0.0);
    if (!skip_row) {
        for (j = 0; j < width; j++) {
            if (top[j] != 0) {
                int adjusted_val = (((511 - bottom[j]) * (511 - bottom[j])) / top[j]);
                if (adjusted_val > 511) adjusted_val = 511;
                dst[j] = top[j] + (511 - adjusted_val - top[j]) * opacity;
            } else {
                dst[j] = top[j];
            }
        }
    } else {
        for (j = 0; j < width; j++) {
            dst[j] = top[j];
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
