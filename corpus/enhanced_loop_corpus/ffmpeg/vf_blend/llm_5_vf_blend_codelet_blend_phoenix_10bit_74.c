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
    for (j = 0; j < width; j++) {
        if (opacity == 0.0) {
            dst[j] = top[j];
            continue;
        }
        uint16_t t = top[j], b = bottom[j];
        uint16_t selected_min = (t > b) ? b : t;
        uint16_t selected_max = (t > b) ? t : b;
        double temp = ((selected_min - selected_max + 1023) - t) * opacity;
        dst[j] = t + temp;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
