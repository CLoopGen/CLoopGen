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
        uint8_t top_val = top[j];
        uint8_t bottom_val = bottom[j];
        int clamped;

        if (top_val >= 250) {
            clamped = top_val;
        } else {
            int div = 255 - top_val;
            int computed = (bottom_val << 8) / div;
            clamped = (computed < 255) ? computed : 255;
            if (clamped < top_val) clamped = top_val;
        }

        dst[j] = top_val + ((clamped - top_val) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
