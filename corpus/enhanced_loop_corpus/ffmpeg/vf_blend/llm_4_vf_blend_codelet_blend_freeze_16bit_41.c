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
        uint16_t top_val = top[j];
        uint16_t bottom_val = bottom[j];
        uint32_t diff = 65535 - top_val;
        uint32_t numerator = diff * diff;
        uint32_t blended = (bottom_val == 0) ? 0 : (numerator / bottom_val);
        uint32_t clamped = (blended > 65535) ? 65535 : blended;
        dst[j] = top_val + ((65535 - top_val - clamped) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
