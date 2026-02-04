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
        uint16_t max_val, min_val;
        for (j = 0; j < width; j++) {
            if (top[j] > bottom[j]) {
                max_val = top[j];
                min_val = bottom[j];
            } else {
                max_val = bottom[j];
                min_val = top[j];
            }
            dst[j] = top[j] + ((min_val - max_val + 65535) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
