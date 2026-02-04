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
        uint16_t top_val1 = top[j];
        uint16_t bot_val1 = bottom[j];
        uint16_t min1 = top_val1 > bot_val1 ? bot_val1 : top_val1;
        uint16_t max1 = top_val1 > bot_val1 ? top_val1 : bot_val1;
        dst[j] = top_val1 + ((min1 - max1 + 4095) - top_val1) * opacity;

        if (j + 1 < width) {
            uint16_t top_val2 = top[j+1];
            uint16_t bot_val2 = bottom[j+1];
            uint16_t min2 = top_val2 > bot_val2 ? bot_val2 : top_val2;
            uint16_t max2 = top_val2 > bot_val2 ? top_val2 : bot_val2;
            dst[j+1] = top_val2 + ((min2 - max2 + 4095) - top_val2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
