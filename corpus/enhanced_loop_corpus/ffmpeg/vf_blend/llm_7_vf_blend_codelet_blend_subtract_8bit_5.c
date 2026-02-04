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
    uint8_t prev_top_j = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint8_t current_top = top[j];
            uint8_t diff = (prev_top_j > (current_top - bottom[j]) ? prev_top_j : (current_top - bottom[j]));
            dst[j] = current_top + ((diff - current_top) * opacity);
            prev_top_j = current_top;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
