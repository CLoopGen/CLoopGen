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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (opacity <= 0.0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                dst[j] = bottom[j];
            }
            dst += dst_linesize;
            bottom += bottom_linesize;
        }
    } else if (opacity >= 1.0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                dst[j] = top[j];
            }
            dst += dst_linesize;
            top += top_linesize;
        }
    } else {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                dst[j] = top[j] * opacity + bottom[j] * (1. - opacity);
            }
            dst += dst_linesize;
            top += top_linesize;
            bottom += bottom_linesize;
        }
    }
}
