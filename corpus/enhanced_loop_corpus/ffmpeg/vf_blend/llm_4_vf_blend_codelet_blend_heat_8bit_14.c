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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint8_t top_val = top[j];
        uint8_t bottom_val = bottom[j];
        if (top_val == 0) {
            dst[j] = top_val + (((0) - top_val) * opacity);
        } else {
            int temp = ((255 - bottom_val) * (255 - bottom_val)) / top_val;
            int clamped_temp = temp > 255 ? 255 : temp;
            dst[j] = top_val + ((255 - clamped_temp - top_val) * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
