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
        int adjusted_opacity = (i & 1) ? (opacity * 0.75) : opacity;

        uint8_t top_val = top[j];
        uint8_t bot_val = bottom[j];
        int blended = (top_val < 128) ? 
            (2 * top_val * bot_val / 255) : 
            (255 - 2 * (255 - top_val) * (255 - bot_val) / 255);

        dst[j] = top_val + (blended - top_val) * adjusted_opacity;

        if (i + 1 < height) {
            dst[dst_linesize + j] = top_val + (blended - top_val) * opacity * 0.5;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
