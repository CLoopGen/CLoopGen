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
        if (top_val != 65535) {
            uint16_t bottom_val = bottom[j];
            uint32_t numerator = (uint32_t)bottom_val << 16;
            uint16_t inv_diff = 65535 - top_val;
            uint16_t blended = (numerator / inv_diff > 65535) ? 65535 : (uint16_t)(numerator / inv_diff);
            dst[j] = top_val + (blended - top_val) * opacity;
        } else {
            dst[j] = 65535;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
