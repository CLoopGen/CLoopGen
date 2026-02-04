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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        double blended = top[j] * opacity + bottom[j] * (1.0 - opacity);
        dst[j] = (uint8_t)blended;
        if (i + 1 < height) {
            uint8_t *dst_next = dst + dst_linesize;
            uint8_t *top_next = top + top_linesize;
            uint8_t *bottom_next = bottom + bottom_linesize;
            dst_next[j] = (uint8_t)(top_next[j] * opacity + bottom_next[j] * (1.0 - opacity));
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
