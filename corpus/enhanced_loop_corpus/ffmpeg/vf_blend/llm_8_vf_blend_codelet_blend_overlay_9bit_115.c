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
        uint16_t top_val1 = top[j], top_val2 = (j2 < width) ? top[j2] : top_val1;
        uint16_t bot_val1 = bottom[j], bot_val2 = (j2 < width) ? bottom[j2] : bot_val1;

        uint16_t result1, result2;
        int diff1 = (top_val1 < 256);
        int diff2 = (top_val2 < 256);

        result1 = diff1 ? ((2 * (top_val1 * bot_val1 / 511))) : (511 - (2 * ((511 - top_val1) * (511 - bot_val1) / 511)));
        result2 = diff2 ? ((2 * (top_val2 * bot_val2 / 511))) : (511 - (2 * ((511 - top_val2) * (511 - bot_val2) / 511)));

        dst[j] = top_val1 + (result1 - top_val1) * opacity;
        if (j2 < width) {
            dst[j2] = top_val2 + (result2 - top_val2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
