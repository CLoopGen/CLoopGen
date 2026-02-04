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
    uint16_t prev_top = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t current_top = top[j];
            dst[j] = prev_top + ((current_top ^ bottom[j]) - current_top) * opacity;
            prev_top = current_top;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
        prev_top = 0;
    }
}
