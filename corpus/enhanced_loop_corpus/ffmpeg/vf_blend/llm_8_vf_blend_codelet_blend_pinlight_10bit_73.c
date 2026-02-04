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
        double opacity_val = opacity * 0.5;
        uint16_t top_val1 = top[j];
        uint16_t bot_val1 = bottom[j];
        uint16_t top_val2 = top[j+1];
        uint16_t bot_val2 = bottom[j+1];

        uint16_t comp1 = (bot_val1 < 512) ? 
            ((top_val1 > 2 * bot_val1) ? (2 * bot_val1) : top_val1) : 
            ((top_val1 > 2 * (bot_val1 - 512)) ? top_val1 : (2 * (bot_val1 - 512)));
        uint16_t comp2 = (bot_val2 < 512) ? 
            ((top_val2 > 2 * bot_val2) ? (2 * bot_val2) : top_val2) : 
            ((top_val2 > 2 * (bot_val2 - 512)) ? top_val2 : (2 * (bot_val2 - 512)));

        dst[j]   = top_val1 + (comp1 - top_val1) * opacity_val;
        dst[j+1] = top_val2 + (comp2 - top_val2) * opacity_val;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
