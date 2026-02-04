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
            ptrdiff_t j1 = j;
            ptrdiff_t j2 = j + 1;
            if (j2 >= width) break;

            uint16_t top_val1 = top[j1];
            uint16_t top_val2 = top[j2];
            uint16_t bot_val1 = bottom[j1];
            uint16_t bot_val2 = bottom[j2];

            dst[j1] = top_val1 + (((bot_val1 < 2048) ? 
                (top_val1 > (2 * bot_val1) ? (2 * bot_val1) : top_val1) : 
                (top_val1 > (2 * (bot_val1 - 2048)) ? top_val1 : (2 * (bot_val1 - 2048)))) - top_val1) * opacity;

            dst[j2] = top_val2 + (((bot_val2 < 2048) ? 
                (top_val2 > (2 * bot_val2) ? (2 * bot_val2) : top_val2) : 
                (top_val2 > (2 * (bot_val2 - 2048)) ? top_val2 : (2 * (bot_val2 - 2048)))) - top_val2) * opacity;
        }
        for (; j < width; j++) {
            dst[j] = top[j] + (((bottom[j] < 2048) ? 
                ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : 
                ((top[j]) > (2 * (bottom[j] - 2048)) ? (top[j]) : (2 * (bottom[j] - 2048)))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
