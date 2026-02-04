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
        int j2 = j + 1;
        uint16_t t0 = top[j], b0 = bottom[j];
        uint16_t t1 = (j2 < width) ? top[j2] : t0;
        uint16_t b1 = (j2 < width) ? bottom[j2] : b0;

        int diff0 = 65535 - t0 - b0;
        int abs_diff0 = (diff0 >= 0) ? diff0 : -diff0;
        dst[j] = t0 + ((65535 - abs_diff0) - t0) * opacity;

        if (j2 < width) {
            int diff1 = 65535 - t1 - b1;
            int abs_diff1 = (diff1 >= 0) ? diff1 : -diff1;
            dst[j2] = t1 + ((65535 - abs_diff1) - t1) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
