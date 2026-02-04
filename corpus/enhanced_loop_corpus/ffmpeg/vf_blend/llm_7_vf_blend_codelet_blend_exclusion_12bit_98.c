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
    uint16_t prev_top = 0, prev_bottom = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t current_top = (j == 0) ? top[j] : prev_top;
            uint16_t current_bottom = (j == 0) ? bottom[j] : prev_bottom;
            dst[j] = current_top + ((current_top + current_bottom - 2 * current_top * current_bottom / 4095) - current_top) * opacity;
            prev_top = top[j];
            prev_bottom = bottom[j];
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
        prev_top = 0;
        prev_bottom = 0;
    }
}
