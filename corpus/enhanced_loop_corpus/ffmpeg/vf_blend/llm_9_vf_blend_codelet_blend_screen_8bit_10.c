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
        int t = top[j];
        int b = bottom[j];
        int blended = 255 - ((255 - t) * (255 - b) / 255);
        int diff = (int)((blended - t) * opacity);
        dst[j] = (uint8_t)(t + diff);
    }
    for (; j < width + 4; j++) {
        if (j < width) {
            dst[j] = top[j];
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
