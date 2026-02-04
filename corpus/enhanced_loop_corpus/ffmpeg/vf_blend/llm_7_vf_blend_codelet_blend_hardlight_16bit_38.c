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
        uint16_t prev_top = top[0];
        for (j = 0; j < width; j++) {
            uint16_t current_top = top[j];
            uint16_t adjusted_bottom = (bottom[j] < 32768) ? 
                ((2) * ((bottom[j] * current_top) / 65535)) : 
                (65535 - (2) * ((65535 - bottom[j]) * (65535 - current_top) / 65535));
            dst[j] = prev_top + (adjusted_bottom - prev_top) * opacity;
            prev_top = current_top;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
