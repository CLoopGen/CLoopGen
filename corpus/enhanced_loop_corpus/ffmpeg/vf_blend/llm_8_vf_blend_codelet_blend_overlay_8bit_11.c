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
    for (j = 0; j < width; j += 2) {
        uint8_t top_val1 = top[j];
        uint8_t bot_val1 = bottom[j];
        uint8_t top_val2 = top[j+1];
        uint8_t bot_val2 = bottom[j+1];

        int result1 = top_val1 + (((top_val1 < 128) ? ((2) * ((top_val1 * bot_val1) / 255)) : (255 - (2) * ((255 - top_val1) * (255 - bot_val1) / 255))) - top_val1) * opacity;
        int result2 = top_val2 + (((top_val2 < 128) ? ((2) * ((top_val2 * bot_val2) / 255)) : (255 - (2) * ((255 - top_val2) * (255 - bot_val2) / 255))) - top_val2) * opacity;

        dst[j] = (uint8_t)(result1 < 0 ? 0 : (result1 > 255 ? 255 : result1));
        if (j + 1 < width) {
            dst[j+1] = (uint8_t)(result2 < 0 ? 0 : (result2 > 255 ? 255 : result2));
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
