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
        int16_t t_val = top[j];
        int16_t b_val = bottom[j];
        int16_t result;
        if (t_val < 2048) {
            result = ((2) * ((t_val * b_val) / 4095));
        } else {
            result = (4095 - (2) * ((4095 - t_val) * (4095 - b_val) / 4095));
        }
        dst[j] = t_val + (result - t_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
